#include<iostream>
#include<iomanip>

void display(int r,int ch,char c){
    for(int i=0;i<=r;i++)
    {
        for(int j=r-i;j>0;j--)
        {
            std::cout<<std::setw(2)<<" ";
        }
        for(int j=i;j<2*i-1;j++)
        {
            if(ch==1)
            {
            std::cout<<std::setw(3)<<j<<" ";
            }
            else
            std::cout<<std::setw(3)<<c<<" ";
        }
        
        std::cout<<std::endl;
    }
}

int main()
{
    int r,ch; char c;
    std::cout<<"Enter the number of rows you want in the pyramid:"<<std::endl;
    std::cin>>r;
    std::cout<<"Enter the character you want to enter"<<std::endl;
    std::cin>>c;
    std::cout<<"Do you want the numbers and alphabets in inceasing order:"<<std::endl;
    std::cin>>ch;
    display(r,ch,c);
    
    std::cin.get();
    return 0;
}