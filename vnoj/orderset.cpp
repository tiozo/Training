#include<iostream>
using namespace std;

class NODE {
public:
    int val,Nth_Node;
    NODE *par,*left, *right;
    NODE() {}
    NODE(const int &x) {
		val=x;
		Nth_Node=1;
		par=NULL;
		left=NULL;
		right=NULL;
	}
    inline void calc(void) {
		int l,r;
		if (left==NULL) l=0; else l=left->Nth_Node;
		if (right==NULL) r=0; else r=right->Nth_Node;
		Nth_Node=l+r+1;
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

void insert(const int&x) {
    NODE *p,*q;
	int dir=0;
	q=NULL;
	p=root;
	while (p!=NULL) {
		if (p->val==x) return;
		q=p;
		if (p->val>x) {
			p=p->left;
			dir=1;
		}
		else {
			p=p->right;
			dir=2;
		}
	}
	create(p,x);
	link(q,p,dir);
	splay(p);
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

void value(const int&k) {
    if (root==NULL || root->Nth_Node<k) {
        cout << "invalid\n";
        return;
    }
    int rem=0,Nth_left;
    NODE *p = root;
    while (true) {
        if (p->left==NULL) Nth_left=0; else Nth_left=p->left->Nth_Node;
        if (rem+Nth_left+1==k) {
            cout << p->val << '\n';
            splay(p);
            return;
        }
        if (rem+Nth_left+1>k) p=p->left;
        else {
            p=p->right;
            rem+=Nth_left+1;
        }
    }
}

void count(const int&k) {
    if (root==NULL) {
        cout << 0 << '\n';
        return;
    }
    int res = 0;
    int Nth_left;
    NODE*p=root;
    while (true) {
        if (p->left==NULL) Nth_left = 0; else Nth_left = p->left->Nth_Node;
        if (p->val<k) {
            res+=Nth_left+1;
            if (p->right!=NULL) p=p->right;
            else break;
        } else {
            if (p->left!=NULL) p=p->left;
            else break;
        }
    }
    cout << res << '\n';
    splay(p);
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    root=NULL;
    int N;
    char type; int p;
    cin >> N;
    while (N--) {
        cin >> type >> p;
        if (type=='I') insert(p); 
        if (type=='D') erase(p); 
        if (type=='K') value(p); 
        if (type=='C') count(p);
    }
}