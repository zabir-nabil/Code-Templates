

/****************************************

@_@
Cat Got Bored *_*
#_#
*****************************************/

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long

#define ull unsigned long long

#define SZ(a) int(a.size())

#define read() freopen("input.txt", "r", stdin)

#define write() freopen("output.txt", "w", stdout)


#define ms(a,b) memset(a, b, sizeof(a))

#define all(v) v.begin(), v.end()

#define PI acos(-1.0)

#define pf printf

#define sfi(a) scanf("%d",&a);

#define sfii(a,b) scanf("%d %d",&a,&b);

#define sfl(a) scanf("%lld",&a);

#define sfll(a,b) scanf("%lld %lld",&a,&b);

#define sful(a) scanf("%llu",&a);

#define sfulul(a,b) scanf("%llu %llu",&a,&b);

#define sful2(a,b) scanf("%llu %llu",&a,&b); // A little different

#define sfc(a) scanf("%c",&a);

#define sfs(a) scanf("%s",a);


#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define cCASE(t) cout<<"Case "<<++t<<": ";

#define INF 1000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

using namespace std;
int a[1003][1003];
int t[3*1005][3*1005];
int tmn[3*1005][3*1005];
int r,c; // x  y
inline int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
inline int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
void build_y (int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry)
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    else
    {
        int my = (ly + ry) / 2;
        build_y (vx, lx, rx, vy*2, ly, my);
        build_y (vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x (int vx, int lx, int rx)
{
    if (lx != rx)
    {
        int mx = (lx + rx) / 2;
        build_x (vx*2, lx, mx);
        build_x (vx*2+1, mx+1, rx);
    }
    build_y (vx, lx, rx, 1, 1, c);
}

int sum_y (int vx, int vy, int tly, int try_, int ly, int ry)
{
    if (ly > ry)
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
           + sum_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
}

int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y (vx, 1, 1, c, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
           + sum_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
}


//For RMQ

void build_y_mn (int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry)
        if (lx == rx)
            tmn[vx][vy] = a[lx][ly];
        else
            tmn[vx][vy] = max(tmn[vx*2][vy] , tmn[vx*2+1][vy]);
    else
    {
        int my = (ly + ry) / 2;
        build_y_mn (vx, lx, rx, vy*2, ly, my);
        build_y_mn (vx, lx, rx, vy*2+1, my+1, ry);
        tmn[vx][vy] = max(tmn[vx][vy*2] , tmn[vx][vy*2+1]);
    }
}

void build_x_mn (int vx, int lx, int rx)
{
    if (lx != rx)
    {
        int mx = (lx + rx) / 2;
        build_x_mn (vx*2, lx, mx);
        build_x_mn (vx*2+1, mx+1, rx);
    }
    build_y_mn (vx, lx, rx, 1, 1, c);
}

int min_y (int vx, int vy, int tly, int try_, int ly, int ry)
{
    if (ly > ry)
        return -INF;
    if (ly == tly && try_ == ry)
        return tmn[vx][vy];
    int tmy = (tly + try_) / 2;
    return max(min_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
               , min_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}

int min_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
    if (lx > rx)
        return -INF;
    if (lx == tlx && trx == rx)
        return min_y (vx, 1, 1, c, ly, ry);
    int tmx = (tlx + trx) / 2;
    return max(min_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
               , min_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}


int main()
{

    sfii(r,c);
    loop(i,1,r)
    {
        loop(j,1,c)
        {
            sfi(a[i][j]);
        }
    }

    build_x(1,1,r);
    build_x_mn(1,1,r);

    int q;
    sfi(q);
    while(q--)
    {

        //int ans = min_x(1,1,r,x1,x2,y1,y2);
        int a,b;
        sfii(a,b);
        int ans = INF;
        int temp_ans = INF;

        loop(i,1,r-a+1)
        {
            int cur_sum = 0;
            int cur_min = INF;
            loop(j,1,c-b+1)
            {
                cur_sum = sum_x(1,1,r,i,i+a-1,j,j+b-1);
                cur_min = min_x(1,1,r,i,i+a-1,j,j+b-1);
                temp_ans = ((a*b)*cur_min) - cur_sum ;
                ans = min(temp_ans,ans);

            }

        }
        pf("%d\n",ans);

    }




    return 0;
}
