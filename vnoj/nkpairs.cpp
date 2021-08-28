#include <algorithm>
#include <cstdio>

typedef long long ll;

using namespace std;

struct loga3d {
   int a[225*225*225];
   int X, Y, Z;

   inline int & transcript( int x, int y, int z ) {
      return a[ ((x-1)*Y + (y-1))*Z + (z-1) ];
   }

   int query( int x0, int y0, int z0 ) {
      int res = 0;
      for( int x = x0; x > 0; x -= x&-x )
         for( int y = y0; y > 0; y -= y&-y )
            for( int z = z0; z > 0; z -= z&-z )
               res += transcript( x, y, z );
      return res;
   }

   int query( int x1, int x2, int y1, int y2, int z1, int z2 ) {
      --x1; x1 = max(x1,0); x2 = min(X,x2);
      --y1; y1 = max(y1,0); y2 = min(Y,y2);
      --z1; z1 = max(z1,0); z2 = min(Z,z2);

      return query( x2, y2, z2 ) 
         - query( x1, y2, z2 ) - query( x2, y1, z2 ) - query( x2, y2, z1 )
         + query( x1, y1, z2 ) + query( x1, y2, z1 ) + query( x2, y1, z1 )
         - query( x1, y1, z1 );
   }

   void update( int x0, int y0, int z0, int val ) {
      for( int x = x0; x <= X; x += x&-x )
         for( int y = y0; y <= Y; y += y&-y )
            for( int z = z0; z <= Z; z += z&-z )
               transcript( x, y, z ) += val;
   }
};

loga3d L;
int B, N, K, M;

struct point {
   int x, y, z;
   int a, b, c, d;
} token[100000];

bool operator < ( const point &P, const point &Q ) { return P.a < Q.a; }
 
int main( void ) {
   scanf( "%d%d%d%d", &B, &N, &K, &M );

   if( B == 1 ) { L.X = 1;   L.Y = 1;   L.Z = 1;   }
   if( B == 2 ) { L.X = 2*M; L.Y = 1;   L.Z = 1;   }
   if( B == 3 ) { L.X = 3*M; L.Y = 3*M; L.Z = 3*M; }

   for( int i = 0; i < N; ++i ) {
      point T;
      if( B == 1 ) {
         scanf( "%d", &T.x ); 
         T.a = T.x; 
         T.b = 1;  
         T.c = 1; 
         T.d = 1;
      }
      if( B == 2 ) {
         scanf( "%d%d", &T.x, &T.y ); 
         T.a = T.x+T.y - 1;
         T.b = T.x-T.y + M;
         T.c = 1; 
         T.d = 1;
      }
      if( B == 3 ) {
         scanf( "%d%d%d", &T.x, &T.y, &T.z );
         T.a = T.x+T.y+T.z - 2;
         T.b = T.x+T.y-T.z + M-1;
         T.c = T.x-T.y+T.z + M-1;
         T.d = T.x-T.y-T.z + M+M;
      }
      token[i] = T;
   }
   sort( token, token+N ); 

   ll res = 0;
   int head = 0, tail = 0;
   while( head < N ) {
      while( token[head].a - token[tail].a > K ) 
         L.update( token[tail].b, token[tail].c, token[tail].d, -1 ), ++tail;

      res += L.query(  token[head].b-K, token[head].b+K,
                       token[head].c-K, token[head].c+K,
                       token[head].d-K, token[head].d+K );

      L.update( token[head].b, token[head].c, token[head].d, 1 ), ++head;
   }

   printf( "%lld\n", res );

   return 0;
}
