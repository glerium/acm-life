#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// order-statistics tree for ranking in each group
// key: tuple<int,int,string,int> => (-wins, -diff, name, teamId)
typedef tuple<int,int,string,int> Key;
typedef tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Msg {
    int teamA; // index 1..3n (A side in message)
    int teamB; // index (B side)
    int scoreA, scoreB;
    bool sameGroup;
    bool adminMarked;
    bool valid;
    Msg(): teamA(0), teamB(0), scoreA(0), scoreB(0), sameGroup(false), adminMarked(false), valid(false) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,k;
        cin>>n>>k;
        int teams = 3*n;
        vector<string> teamName(teams+1);
        vector<int> groupOf(teams+1);
        unordered_map<string,int> name2team; name2team.reserve(4*teams);
        // read team lines: each line: teamName, 5 player names, groupId
        for(int i=1;i<=teams;i++){
            string t; cin>>t;
            teamName[i]=t;
            for(int j=0;j<5;j++){
                string p; cin>>p;
                name2team[p]=i; // player -> team
            }
            int g; cin>>g;
            groupOf[i]=g;
            name2team[t]=i; // team name -> team
        }

        // Prepare structures
        vector<Msg> msgs(1); // index from 1, msgs[0] unused
        // For mapping unordered pair to vector of message ids in chronological order:
        // encode pair key as (min*MAX + max)
        const int MAXT = 5000;
        unordered_map<long long, vector<int>> pair_msgs; pair_msgs.reserve(k*2+10);
        unordered_map<long long, int> active_msg; // key -> currently active msg id (or -1)
        // team stats
        vector<int> wins(teams+1,0), diff(teams+1,0);
        // for each team, store current key for its group's ordered_set
        vector<Key> curKey(teams+1);

        // per group ordered set
        // group indices presumably small (1..3), but problem says groups numbered maybe arbitrary; we will map group id -> ordered_set
        unordered_map<int, ordered_set> groupSet;

        // initialize group sets and insert all teams with initial stats (0,0)
        for(int i=1;i<=teams;i++){
            int g = groupOf[i];
            if(groupSet.find(g)==groupSet.end()){
                groupSet.emplace(g, ordered_set());
            }
        }
        for(int i=1;i<=teams;i++){
            int g = groupOf[i];
            Key key = make_tuple(0, 0, teamName[i], i); // note we store -wins and -diff, so zeros
            curKey[i]=key;
            groupSet[g].insert(key);
        }

        // helper to encode pair
        auto pair_key = [&](int a, int b)->long long{
            int x = min(a,b), y = max(a,b);
            return (long long)x * MAXT + y;
        };

        // helper to apply or revoke a msg's effect (apply = +1, revoke = -1)
        auto apply_msg_effect = [&](int msgid, int sign){
            Msg &m = msgs[msgid];
            int A = m.teamA, B = m.teamB;
            int sA = m.scoreA, sB = m.scoreB;
            // remove old keys from group ordered set, update stats, then reinsert
            int gA = groupOf[A], gB = groupOf[B];
            // erase old keys
            groupSet[gA].erase(curKey[A]);
            groupSet[gB].erase(curKey[B]);

            // adjust wins
            if(sign==1){
                if(sA > sB) wins[A]++, /*wins[B] unchanged*/ wins[B]+=0;
                else wins[B]++, wins[A]+=0;
                diff[A] += (sA - sB);
                diff[B] += (sB - sA);
            }else{ // revoke
                if(sA > sB) wins[A]--, wins[B]+=0;
                else wins[B]--, wins[A]+=0;
                diff[A] -= (sA - sB);
                diff[B] -= (sB - sA);
            }
            // reinsert with new keys
            Key keyA = make_tuple(-wins[A], -diff[A], teamName[A], A);
            Key keyB = make_tuple(-wins[B], -diff[B], teamName[B], B);
            curKey[A]=keyA; curKey[B]=keyB;
            groupSet[gA].insert(keyA);
            groupSet[gB].insert(keyB);
        };

        // process k operations
        int totalMsgs = 0;
        string restOfLine;
        for(int opi=0; opi<k; ++opi){
            int op; cin>>op;
            if(op==1){
                // read the rest of the line as the formatted sentence
                // consume space
                getline(cin, restOfLine);
                string s = restOfLine;
                // format guaranteed: " a fan of A: The score of our game against Team B is a-b."
                // trim leading spaces
                while(!s.empty() && isspace(s.front())) s.erase(s.begin());
                // parse A between "a fan of " and ":"
                string marker1 = "a fan of ";
                size_t pos1 = s.find(":");
                string Aname;
                if(pos1!=string::npos){
                    // substring from after marker1 to pos1
                    size_t start = s.find(marker1);
                    if(start!=string::npos){
                        start += marker1.size();
                        Aname = s.substr(start, pos1 - start);
                    } else {
                        // fallback: take up to :
                        Aname = s.substr(0, pos1);
                    }
                } else {
                    // shouldn't happen
                    Aname = "";
                }
                // parse B: find "Team " then " is "
                string teamMarker = "Team ";
                size_t posTeam = s.find(teamMarker);
                string Bname;
                if(posTeam!=string::npos){
                    posTeam += teamMarker.size();
                    size_t posIs = s.find(" is ", posTeam);
                    if(posIs!=string::npos){
                        Bname = s.substr(posTeam, posIs - posTeam);
                    } else {
                        // fallback
                        // find " is"
                        size_t p = s.find(" is", posTeam);
                        if(p!=string::npos) Bname = s.substr(posTeam, p-posTeam);
                    }
                }
                // parse scores: find " is " and then something like "a-b."
                int aScore=0, bScore=0;
                size_t posIs2 = s.rfind(" is ");
                if(posIs2!=string::npos){
                    size_t start = posIs2 + 4;
                    string scorePart = s.substr(start);
                    // remove trailing dot/space
                    while(!scorePart.empty() && isspace(scorePart.back())) scorePart.pop_back();
                    if(!scorePart.empty() && scorePart.back()=='.') scorePart.pop_back();
                    // now format "a-b"
                    size_t dash = scorePart.find('-');
                    if(dash!=string::npos){
                        string sa = scorePart.substr(0,dash);
                        string sb = scorePart.substr(dash+1);
                        // trim
                        auto trim = [&](string &t){
                            while(!t.empty() && isspace(t.front())) t.erase(t.begin());
                            while(!t.empty() && isspace(t.back())) t.pop_back();
                        };
                        trim(sa); trim(sb);
                        aScore = stoi(sa);
                        bScore = stoi(sb);
                    }
                }

                // map Aname (maybe player or team) to team index
                int teamAidx = name2team[Aname];
                int teamBidx = name2team[Bname];

                // create message
                Msg m;
                m.teamA = teamAidx;
                m.teamB = teamBidx;
                m.scoreA = aScore;
                m.scoreB = bScore;
                m.adminMarked = false;
                m.valid = false;
                m.sameGroup = (groupOf[teamAidx] == groupOf[teamBidx]);

                msgs.push_back(m);
                ++totalMsgs;
                int mid = totalMsgs;

                long long key = pair_key(teamAidx, teamBidx);
                pair_msgs[key].push_back(mid);

                // check if should become active: active_msg[key] absent or -1, and message sameGroup and not adminMarked
                int curActive = -1;
                if(active_msg.find(key)!=active_msg.end()) curActive = active_msg[key];
                if(curActive==0) curActive = -1;
                if(curActive == -1 && m.sameGroup && !m.adminMarked){
                    // activate this message
                    msgs[mid].valid = true;
                    active_msg[key] = mid;
                    // apply its effect
                    apply_msg_effect(mid, +1);
                } else {
                    // remains invalid (either because different group or already an active earlier message)
                    msgs[mid].valid = false;
                    if(active_msg.find(key)==active_msg.end()) active_msg[key] = -1;
                }
            }
            else if(op==2){
                int x; cin>>x; // admin marks x-th forum message invalid
                if(x<=0 || x>totalMsgs) {
                    // as problem said x <= existing messages; but be safe
                    continue;
                }
                Msg &m = msgs[x];
                if(m.adminMarked){
                    // already marked before => do nothing
                    continue;
                }
                // mark
                m.adminMarked = true;
                if(!m.valid){
                    // was not active, nothing else
                    continue;
                } else {
                    // was active: need to revoke its effect and find next earliest non-admin message in that pair
                    long long key = pair_key(m.teamA, m.teamB);
                    // revoke effect
                    msgs[x].valid = false;
                    apply_msg_effect(x, -1);
                    // find next earliest in pair_msgs[key]
                    int newActive = -1;
                    for(int id : pair_msgs[key]){
                        if(!msgs[id].adminMarked && msgs[id].sameGroup && id!=x){
                            // the earliest such (they are in chronological order), but we must ensure it isn't the same x
                            newActive = id; break;
                        }
                    }
                    if(newActive==-1){
                        active_msg[key] = -1;
                    } else {
                        msgs[newActive].valid = true;
                        active_msg[key] = newActive;
                        apply_msg_effect(newActive, +1);
                    }
                }
            }
            else if(op==3){
                int x; cin>>x; // query team x current group rank
                int g = groupOf[x];
                // key for team x
                Key kx = curKey[x];
                int pos = groupSet[g].order_of_key(kx); // 0-based
                cout << (pos+1) << "\n";
            }
        } // end k ops
    } // end T
    return 0;
}
