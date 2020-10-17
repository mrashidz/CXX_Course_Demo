#include <iostream>
#include <vector>


int main() {
    std::vector< std::vector<int> > v;
    std::vector<int> a,b = {-5,-4,-3,-2,-1,0,1};
        
    a.insert(a.begin(),b.cbegin(),b.cbegin()+4);
    b.pop_back();

    v.push_back(a);
    v.push_back(b);
    
    v[0].push_back(11);
    v[1][2] = 13;

    for (std::vector<int> e: v) {
        std::cout << ">>> ";
        for (auto i = e.cbegin(); i < e.cend();i ++)
            std::cout << *i << " ";
        std::cout << std::endl;
    }

    return 0;    
}




