int a(int x){
    int y=x+x;
    return y;
}

int b(int x){
    int y=x*x;
    return y;
}

int main(){
    int m=1,n=2;

    if(m>0)
        return a(m);
    else
        return b(n);
}