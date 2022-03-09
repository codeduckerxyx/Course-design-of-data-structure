#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define CAS int casen;scanf("%d",&casen);for(int LP=1;LP<=casen;++LP)
inline void intxt(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
}
const ll mod=998244353;

const int N=2e5+15;
const int M=1e6+5;

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

class num1{
private:
    map<string,string> pre;
    map<string,int> step;
    queue<string> q;
    string Begin_state,End_state;

    void Read_Data(){
        cin>>Begin_state;
        cin>>End_state;
        for(auto &x:Begin_state) if(x=='0') x=' ';
        for(auto &x:End_state) if(x=='0') x=' ';
    }

    bool Move_state(string now){
        q.pop();
        int x,y,tem_step=step[now];

        for(int i=0;i<9;i++){
            if( now[i]==' ' ){
                x = i/3 ; y = i%3;
                break;
            }
        }

        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if( new_x>=0 && new_x<=2 && new_y>=0 && new_y<=2 ){
                string tem=now;
                swap( tem[x*3+y],tem[new_x*3+new_y] );
                if( 0==step.count( tem ) ){
                    step[tem]=tem_step+1;
                    pre[tem]=now;
                    q.push(tem);
                    if(tem==End_state) return 1;
                }
            }
        }
        return 0;
    }

    void _print(string &s){
        cout<<"   "<<s[0]<<s[1]<<s[2]<<endl;
        cout<<"   "<<s[3]<<s[4]<<s[5]<<endl;
        cout<<"   "<<s[6]<<s[7]<<s[8]<<endl;
    }

    void print(){

        stack<string> sta;
        sta.push( End_state );

        while( 1==pre.count( sta.top() ) ){
            sta.push( pre[sta.top()] );
        }

        cout<<endl<<endl;
        cout<<"S_0 is :"<<endl;
        _print(Begin_state);

        while( !sta.empty() ){
            if( sta.top()!=Begin_state && sta.top()!=End_state ){
                cout<<" ............ "<<endl<<endl;
                _print(sta.top());
                cout<<endl;
            }
            sta.pop();
        }

        cout<<" ............ "<<endl<<endl;
        cout<<"S_g is :"<<endl;
        _print(End_state);

    }

public:
    void solve(){
        Read_Data();
        q.push(Begin_state);
        step[Begin_state]=0;
        if( Begin_state!=End_state )
            while( !q.empty() && !Move_state(q.front()) );
        print();
        if( step.count(End_state)==1 )
            cout<<"Total "<< step[End_state] <<" steps!"<<endl;
        else
            cout<<"No solution!"<<endl;
    }
    int Number_of_States_Searched(){
        return step.size();
    }
};

class num2{
private:
    queue<string> qp,qs;
    string Begin_state,End_state,key_str;
    map<string,string> pre,suf;
    map<string,int> stepp,steps;

    void Read_Data(){
        cin>>Begin_state;
        cin>>End_state;
        for(auto &x:Begin_state) if(x=='0') x=' ';
        for(auto &x:End_state) if(x=='0') x=' ';
    }

    bool p_Move_state(string now){
        qp.pop();
        int x,y,tem_step=stepp[now];

        for(int i=0;i<9;i++){
            if( now[i]==' ' ){
                x = i/3 ; y = i%3;
                break;
            }
        }

        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if( new_x>=0 && new_x<=2 && new_y>=0 && new_y<=2 ){
                string tem=now;
                swap( tem[x*3+y],tem[new_x*3+new_y] );
                if( 0==stepp.count( tem ) ){
                    stepp[tem]=tem_step+1;
                    pre[tem]=now;
                    qp.push(tem);
                    if( 1==steps.count( tem ) ) {key_str=tem;return 1;}
                }
            }
        }
        return 0;
    }
    bool s_Move_state(string now){
        qs.pop();
        int x,y,tem_step=steps[now];

        for(int i=0;i<9;i++){
            if( now[i]==' ' ){
                x = i/3 ; y = i%3;
                break;
            }
        }

        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if( new_x>=0 && new_x<=2 && new_y>=0 && new_y<=2 ){
                string tem=now;
                swap( tem[x*3+y],tem[new_x*3+new_y] );
                if( 0==steps.count( tem ) ){
                    steps[tem]=tem_step+1;
                    suf[tem]=now;
                    qs.push(tem);
                    if( 1==stepp.count( tem ) ) {key_str=tem;return 1;}
                }
            }
        }
        return 0;
    }

    void _print(string &s){
        cout<<"   "<<s[0]<<s[1]<<s[2]<<endl;
        cout<<"   "<<s[3]<<s[4]<<s[5]<<endl;
        cout<<"   "<<s[6]<<s[7]<<s[8]<<endl;
    }

    void print(){

        queue<string> que;
        que.push(key_str);
        string tem=key_str;
        while( 1==suf.count( tem ) ){
            tem=suf[tem];
            que.push( tem );
            //cout<<que.front()<<endl;
        }

        stack<string> sta;
        sta.push( key_str );

        while( 1==pre.count( sta.top() ) ){
            sta.push( pre[sta.top()] );
        }

        cout<<endl<<endl;
        cout<<"S_0 is :"<<endl;
        _print(Begin_state);

        while( !sta.empty() ){
            if( sta.top()!=Begin_state && sta.top()!=End_state ){
                cout<<" ............ "<<endl<<endl;
                _print(sta.top());
                cout<<endl;
            }
            sta.pop();
        }

        que.pop();
        while( !que.empty() ){
            if( que.front()!=Begin_state && que.front()!=End_state ){
                cout<<" ............ "<<endl<<endl;
                _print(que.front());
                cout<<endl;
            }
            que.pop();
        }

        cout<<" ............ "<<endl<<endl;
        cout<<"S_g is :"<<endl;
        _print(End_state);

    }


public:
    void solve(){
        Read_Data();
        qp.push(Begin_state);
        qs.push(End_state);
        stepp[Begin_state]=0;
        steps[End_state]=0;
        bool flag=0;
        if( Begin_state!=End_state ){
            while( !qp.empty() || !qs.empty() ){
                while( (!qp.empty() && !qs.empty() && stepp[qp.front()]<=steps[qs.front()]) || (!qp.empty() && qs.empty()) ){
                    if( 1==p_Move_state( qp.front() ) ){ flag=1;break; }
                }
                if(flag) break;
                while( (!qp.empty() && !qs.empty() && stepp[qp.front()]>steps[qs.front()]) || (qp.empty() && !qs.empty()) ){
                    if( 1==s_Move_state( qs.front() ) ){ flag=1;break; }
                }
                if(flag) break;
            }
        }
        print();
        if( flag==1 || Begin_state==End_state )
            cout<<"Total "<< stepp[key_str]+steps[key_str] <<" steps!"<<endl;
        else
            cout<<"No solution!"<<endl;
    }

    int Number_of_States_Searched(){
        return steps.size()+stepp.size();
    }
};

class num3{
private:
    map<string,string> pre;
    map<string,int> step;
    string Begin_state,End_state;
    priority_queue< pair<int,string> , vector<pair<int,string>> , greater< pair<int,string>> > q;
    int wx[10],wy[10];

    void inta(){
        for(int i=0;i<9;i++){
            if( End_state[i]>='1' && End_state[i]<='8' ){
                wx[ End_state[i]-'0' ]=i/3; wy[ End_state[i]-'0' ]=i%3;
            }
        }
    }

    void Read_Data(){
        cin>>Begin_state;
        cin>>End_state;
        for(auto &x:Begin_state) if(x=='0') x=' ';
        for(auto &x:End_state) if(x=='0') x=' ';
    }

    //Calculate the Huffman distance from the now state to the End state
    int cal_value( string s ){
        int sum=0;
        for(int i=0;i<9;i++){
            if( s[i]>='1' && s[i]<='8' ){
                sum+= abs( i/3-wx[ s[i]-'0' ] );
                sum+= abs( i%3-wy[ s[i]-'0' ] );
            }
        }
        return sum;
    }

    bool Move_state(string now){
        q.pop();
        int x,y,tem_step=step[now];

        for(int i=0;i<9;i++){
            if( now[i]==' ' ){
                x = i/3; y = i%3;
                break;
            }
        }

        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if( new_x>=0 && new_x<=2 && new_y>=0 && new_y<=2 ){
                string tem=now;
                swap( tem[x*3+y],tem[new_x*3+new_y] );
                if( 0==step.count( tem ) ){
                    step[tem]=tem_step+1;
                    pre[tem]=now;
                    q.push( make_pair( tem_step+1+cal_value(tem),tem) );
                    if(tem==End_state) return 1;
                }
            }
        }
        return 0;
    }

    void _print(string &s){
        cout<<"   "<<s[0]<<s[1]<<s[2]<<endl;
        cout<<"   "<<s[3]<<s[4]<<s[5]<<endl;
        cout<<"   "<<s[6]<<s[7]<<s[8]<<endl;
    }

    void print(){

        stack<string> sta;
        sta.push( End_state );

        while( 1==pre.count( sta.top() ) ){
            sta.push( pre[sta.top()] );
        }

        cout<<endl<<endl;
        cout<<"S_0 is :"<<endl;
        _print(Begin_state);

        while( !sta.empty() ){
            if( sta.top()!=Begin_state && sta.top()!=End_state ){
                cout<<" ............ "<<endl<<endl;
                _print(sta.top());
                cout<<endl;
            }
            sta.pop();
        }

        cout<<" ............ "<<endl<<endl;
        cout<<"S_g is :"<<endl;
        _print(End_state);

    }

public:
    void solve(){
        Read_Data();
        inta();
        q.push( make_pair( 0+cal_value( Begin_state ),Begin_state ) );
        step[Begin_state]=0;
        if( Begin_state!=End_state )
            while( !q.empty() && !Move_state( q.top().second ) );
        print();
        if( step.count(End_state)==1 )
            cout<<"Total "<< step[End_state] <<" steps!"<<endl;
        else
            cout<<"No solution!"<<endl;
    }
    int Number_of_States_Searched(){
        return step.size();
    }
};

class num4{
public:
    int fact[9];
    bool vis[362880];
    map<string, string> pre;
    typedef struct{
        string s;
        int step;
        int k;          //'x'在第k位
    }Point;
    int permutation_hash(string s)          //求长度为9的字符串某种排列的哈希值
    {
        int ans = 0;
        for(int i = 0; i < 9; i ++)
        {
            int d = 0;
            for(int j = 0; j < i; j ++)
                if(s[j] > s[i])  d ++;      //求s[i]与其前面的字符组成的逆序对个数
            ans += d * fact[i];
        }
        return ans;
    }

    void _print(string s){
        cout<<"   "<<s[0]<<s[1]<<s[2]<<endl;
        cout<<"   "<<s[3]<<s[4]<<s[5]<<endl;
        cout<<"   "<<s[6]<<s[7]<<s[8]<<endl;
        cout << "  ...." << endl;
    }

    int bfs(Point p, string ed)
    {
        vis[permutation_hash(p.s)] = true;
        queue<Point> q;
        q.push(p);
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            if(p.s == ed)  return p.step;

            int x = p.k / 3;      //'x'的行数
            int y = p.k % 3;      //'x'的列数
            Point next;
            next.step = p.step + 1;
            for(int i = 0; i < 4; i ++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2)
                {
                    next.k = nx * 3 + ny;           //求出'x'在字符串中的的新位置

                    next.s=p.s;
                    next.s[p.k] = p.s[next.k];      //先用即将和'x'交换的字符覆盖'x'之前的位置
                    next.s[next.k] = 'x';           //再给'x'的新位置赋值'x'

                    int hash = permutation_hash(next.s);
                    if(!vis[hash])
                    {
                        pre[next.s] = p.s;
                        vis[hash] = true;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }

    void solve(){
        fact[0] = 1;
        for(int i = 1; i < 9; i ++)  fact[i] = fact[i - 1] * i;    //预处理fact[i] = i!

        Point start;
        cin >> start.s;
        for(int i = 0; i < 9; i ++)
        {
          if(start.s[i]=='x')start.k=i;
        }
        start.step = 0;
        string ed;
        cin >> ed;
        printf("%d\n",bfs(start,ed));
        stack<string> st;
        for (string str = ed; str != start.s;str=pre[str]){
            st.push(str);
        }
        st.push(start.s);
        while(!st.empty())
        {
            string t = st.top();
            _print(t);
            st.pop();
        }
    }

};

int main(){
    intxt();
//num1:Ordinary BFS            by xyx
//num2:Bidirectional BFS       by xyx
//num3:A*                      by xyx
//num4:Cantor expansion + BFS  by yxy
    num4 a;
    a.solve();
    //cout<<"Number_of_States_Searched : "<<a.Number_of_States_Searched()<<endl;//num1,num2,num3
    return 0;
}
//Input format:
/**  num1,num2,num3
283104765
123804765
**/
/**  num4
2831x4765
1238x4765
**/


