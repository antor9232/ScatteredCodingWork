#include<iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n, r1,r2,m;
    std::cin>>n;
    int64_t l=1, r=n;
    while(r-1)
    {
        m = (1+r)/2;
        std::cout<<"? "<<m<<'\n'; std::cout.flush();
        std::cin >> r1;
        std::cout<<"? "<<m+1<<'\n'; std::cout.flush();
        std::cin >> r2;
        if(r2>r1) r=m;
        else l = m+1;
    }
    std::cout<<"! "<<l<<'\n';
    return 0;
}