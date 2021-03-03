struct node{
    int x, y, mn;
    node* l;
    node* r;
    node(){}
    node(int x) : x(x), y(rand()), mn(x), l(0), r(0){}
};

using pnode = node*;
using pnn = pair<pnode, pnode>;

int get_min(pnode t){
    return t ? t->mn  : inf;
}

void upd(pnode t){
    t->mn = min(min(get_min(t->l), get_min(t->r)), t->x);
}

pnode merge(pnode l, pnode r){
    if (!l) return r;
    if (!r) return l;
    pnode res;
    if (l->y < r->y){
        l->r = merge(l->r, r);
        res = l;
    }
    else{
        r->l = merge(l, r->l);
        res = r;
    }
    upd(res);
    return res;
}

pnn split(pnode t, int x){
    if (!t) return {0, 0};
    pnn res;
    if (t->x < x){
        res = split(t->r, x);
        t->r = res.x;
        res.x = t;
    }
    else{
        res = split(t->l, x);
        t->l = res.y;
        res.y = t;
    }
    upd(t);
    return res;
}

pnode root[N];

void insert(int i, int x){
    pnode nt = new node(x);
    pnn p = split(root[i], x);
    root[i] = merge(merge(p.x, nt), p.y);
}

void query(int x, int y, int k){
    pnn pp = split(root[x], k);
    root[x] = pp.x;
    pnode t = pp.y;
        pp = split(root[y], get_min(t)+1);
    root[y] = pp.x;
    pnode p = pp.y;
    while (t){
        pnn pt = split(t, get_min(p)+1);
        root[y] = merge(root[y], pt.x);
        t = pt.y;
        swap(t, p);
    }
    root[y] = merge(root[y], p);
}


void print(pnode t){
    if (!t) return;
    print(t->l);
    cout << t->x;
    print(t->r);
}
