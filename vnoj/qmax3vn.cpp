#include<iostream>
using namespace std;

class NODE {
public:
    int val,Nth_Node,maxval;
    NODE *par,*left, *right;
    NODE() {}
    NODE(const int &x) {
		val=x;
		Nth_Node=1;
        maxval = x;
		par=NULL;
		left=NULL;
		right=NULL;
	}
    inline void calc(void) {
		int l,r;
		if (left==NULL) l=0; else l=left->Nth_Node;
		if (right==NULL) r=0; else r=right->Nth_Node;
		Nth_Node=l+r+1;
        if (left==NULL) l = -1e9; else l=left->maxval;
        if (right==NULL) r = -1e9; else r=right->maxval;
        maxval = max(max(l,r),val);
	}
	inline bool isLeft(const NODE *a) const {
		return (a!=NULL && left==a);
	}
	inline bool isRight(const NODE *a) const {
		return (a!=NULL && right==a);
	}
};

NODE *root;

void create(NODE *&a,const int &x) {
	if (a!=NULL) return;
	a=new NODE(x);
}

void link(NODE*a,NODE*b,int dir) {
    if (a==NULL) {
		root=b;
		if (root!=NULL) root->par=NULL;
		return;
	}
	if (dir==1) a->left=b; else a->right=b;
	if (b!=NULL) b->par=a;
}

void left_rotation(NODE *a) {
    NODE *b,*c;
	int dir=0;
	c=a->par;
	if (c!=NULL) {
		if (c->isLeft(a)) dir=1; else dir=2;
	}
	b=a->right;
	link(a,b->left,2);
	link(b,a,1);
	link(c,b,dir);
    a->calc();
    b->calc();
}

void right_rotation(NODE *a) {
    NODE *b,*c;
	int dir=0;
	c=a->par;
	if (c!=NULL) {
		if (c->isLeft(a)) dir=1; else dir=2;
	}
	b=a->left;
	link(a,b->right,1);
	link(b,a,2);
	link(c,b,dir);
    a->calc();
    b->calc();
}

inline void splay(NODE*a) {
    while (a->par!=NULL) {
        if (a->par->par==NULL) {
            if (a->par->isLeft(a)) {
                right_rotation(a->par);
                a->right->calc();
            } else {
                left_rotation(a->par);
                a->left->calc();
            }
        } else {
            if (a->par->isLeft(a)) {
                if (a->par->par->isLeft(a->par)) {
                    right_rotation(a->par->par);
                    right_rotation(a->par);
                    a->right->right->calc();
                    a->right->calc();
                } else {
                    right_rotation(a->par);
                    left_rotation(a->par);
                    a->left->calc();
                    a->right->calc();
                }
            } else {
                if (a->par->par->isRight(a->par)) {
                    left_rotation(a->par->par);
                    left_rotation(a->par);
                    a->left->left->calc();
                    a->left->calc();
                } else {
                    left_rotation(a->par);
                    right_rotation(a->par);
                    a->right->calc();
                    a->left->calc();
                }
            }
        }
        a->calc();
    }
}

void find(const int &v) {
    if (root==NULL) return;
    NODE *p=root;
    while (true) {
        if (p->val==v) break;
        if (p->val>v) {
            if (p->left!=NULL) p=p->left;
            else break;
        }
        if (p->val<v) {
            if (p->right!=NULL) p=p->right;
            else break;
        }
    }
    splay(p);
}

void split(const int &v,NODE*&a) {
    if (root== NULL) {
        a = NULL;
        return;
    }
    find(v);
    a=root->right;
    if (a!=NULL) a->par=NULL;
    root->right=NULL;
    root->calc();
}

void merge(NODE*a) {
    if (root==NULL) {
        link(NULL,a,1);
        return;
    }
    NODE*p = root;
    while (p->right!=NULL) p=p->right;
    splay(p);
    link(p,a,2);
    p->calc();
}

void insert(const int &i,const int&x) {
    NODE *p,*q;
	int dir=0,Nth_left,rem = 0;
	q=NULL;
	p=root;
	while (p!=NULL) {
		q=p;
        if (p->left==NULL) Nth_left=0; else Nth_left=p->left->Nth_Node;
		if (rem+Nth_left+1>=i) {
			p=p->left;
			dir=1;
		}
		else {
            rem+=Nth_left+1;
			p=p->right;
			dir=2;
		}
	}
    if (p==NULL) {
	    create(p,x);
        if (root==NULL) root = p;
        else {
            link(q,p,dir);
            splay(p);
        }
    }
}

void erase(const int&v) {
    NODE *p,*l;
    split(v,p);
    if (root==NULL || root -> val != v) {
        merge(p);
        return;
    }
    l=root->left;
    delete root;
    link(NULL,l,1);
    merge(p);
}

int maxhigh(NODE*a,int l,int r,int u,int v) {
    if (l>v || r<u || l>r || v<u) return (-1e9);
    if (a==NULL) return (-1e9);
    if (u<=l && r<=v) return (a->maxval);
    int Nth_left;
    if (a->left==NULL) Nth_left = 0;
    else Nth_left = a->left->Nth_Node;
    int left = maxhigh(a->left,l,l+Nth_left-1,u,v);
    int right = maxhigh(a->right,l+Nth_left+1,r,u,v);
    int mid;
    if (u<=l+Nth_left && l+Nth_left<=v) mid = a->val; else mid = -1e9;
    return (max(max(left,mid),right));
}

int N;
int value(const int&u,const int&v) {
    return maxhigh(root,1,N,u,v);
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    root=NULL;
    int q;
    char type; int u,v;
    cin >> q;
    while (q--) {
        cin >> type >> u >> v;
        if (type=='A') {insert(v,u); N++;}
        else cout << value(u,v) << '\n';
    }
}