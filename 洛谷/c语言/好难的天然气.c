#include <stdio.h> //数组的应用
int main(){
    int gas[12];
    for (int i=0;i<12;i++){
        scanf("%d",&gas[i]);
    }
    double total_cost=0;
    double total_gas=0;
    for (int i=0;i<12;i++){
        int current_gas=gas[i];
        int remaining_gas=current_gas;
        double current_cost=0.0;
        if (total_gas<310){
            int fisrt_part=310-total_gas;
            if (fisrt_part<=remaining_gas){
                current_cost+=fisrt_part*3.0;
                remaining_gas-=fisrt_part;
            }
            else {current_cost+=remaining_gas*3.0;
                remaining_gas=0;
            }        
        }
        if (total_gas>0&&total_gas<520){
            int second_part=520-total_gas;
            if (second_part<=remaining_gas){
                current_cost+=second_part*3.3;
                remaining_gas-=second_part;
            }
            else {current_cost+=remaining_gas*3.3;
                remaining_gas=0;
            } 
        }
        if (total_gas>520){
            current_cost+=remaining_gas*4.2;
        }
        total_gas+=current_gas;
        printf("%.1lf\n",current_cost);
    }
    return 0;
}