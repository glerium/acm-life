#include <bits/stdc++.h>
using namespace std;
int N, tdef, tmin, tmax;
string h;
struct Address {
    string owner;
    int expire;
};
map<int, Address> nalloc, toalloc, alloced, expired;
map<string, set<int>> allocer;
map<int, int> expire_time;
struct AddressExpire {
    int id;
    int expire;
    bool operator<(const AddressExpire& rhs)const {
        return expire > rhs.expire;
    }
};
priority_queue<AddressExpire> q;
enum status {
    nalloc_, toalloc_, alloced_, expired_
};
status check_status(int id) {
    if(nalloc.count(id)) return nalloc_;
    else if(toalloc.count(id)) return toalloc_;
    else if(alloced.count(id)) return alloced_;
    else return expired_;
}
string get_owner(int id) {
    if(nalloc.count(id)) return nalloc[id].owner;
    else if(toalloc.count(id)) return toalloc[id].owner;
    else if(alloced.count(id)) return alloced[id].owner;
    else return expired[id].owner;
}
Address erase_ip(int id) {
    Address address;
    if(nalloc.count(id)) {
        address = nalloc[id];
        nalloc.erase(id);
    }else if(toalloc.count(id)) {
        address = toalloc[id];
        toalloc.erase(id);
    }else if(alloced.count(id)) {
        address = alloced[id];
        alloced.erase(id);
    }else {
        address = expired[id];
        expired.erase(id);
    }
    return address;
}
void expire_ip(int tm) {
    while(!q.empty() && q.top().expire <= tm) {
        AddressExpire address = q.top(); q.pop();
        if(expire_time[address.id] != address.expire)
            continue;
        status stt = check_status(address.id);
        if(stt != status::toalloc_ && stt != status::alloced_)
            continue;
        Address ipp = erase_ip(address.id);
        allocer[ipp.owner].erase(address.id);
        ipp.expire = -1;
        if(stt == status::toalloc_) {
            nalloc[address.id] = ipp;
        }else if(stt == status::alloced_) {
            expired[address.id] = ipp;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> N >> tdef >> tmax >> tmin >> h;
    for(int i=1;i<=N;i++)
        nalloc.insert({i, {"", -1}});
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        int tm;
        string send, recv;
        string type;
        int ip;
        int expi;
        cin >> tm >> send >> recv >> type >> ip >> expi;
        expire_ip(tm);
        if(recv != h && recv != "*" && type != "REQ")
            continue;
        if(type == "DIS") {
            int ip = -1;
            int expires_at = expi;
            if(expi == 0)
                expires_at = tm + tdef;
            else if(expires_at > tmax + tm)
                expires_at = tmax + tm;
            else if(expires_at < tmin + tm)
                expires_at = tmin + tm;
            if(allocer.count(send) && !allocer[send].empty()) {
                ip = *allocer[send].begin();
            } else if(!nalloc.empty()) {
                ip = nalloc.begin()->first;
            } else if(!expired.empty()) {
                ip = expired.begin()->first;
            } else{
                continue;
            }
            erase_ip(ip);
            toalloc[ip].expire = expires_at;
            toalloc[ip].owner = send;
            allocer[send].insert(ip);
            expire_time[ip] = expires_at;
            q.push({ip, expires_at});
            cout << h << " " << send << " OFR " << ip << " " << expires_at << endl;
        } else if(type == "REQ") {
            if(recv != h) {
                auto ips = allocer[send];
                for(auto ip : ips) {
                    if(check_status(ip) == status::toalloc_) {
                        auto ipp = toalloc[ip];
                        toalloc.erase(ip);
                        nalloc.insert({ip, ipp});
                        allocer[ipp.owner].erase(ip);
                    }
                }
            }else if(!(1 <= ip && ip <= N && get_owner(ip) == send)) {
                cout << h << " " << send << " NAK " << ip << " " << 0 << endl;
            }else {
                auto address = erase_ip(ip);
                int expires_at = expi;
                if(expi == 0)
                    expires_at = tm + tdef;
                else if(expires_at > tmax + tm)
                    expires_at = tmax + tm;
                else if(expires_at < tmin + tm)
                    expires_at = tmin + tm;
                address.expire = expires_at;
                alloced.insert({ip, address});
                expire_time[ip] = expires_at;
                q.push({ip, expires_at});
                cout << h << " " << send << " ACK " << ip << " " << expires_at << endl;
            }
        }
    }
    return 0;
}