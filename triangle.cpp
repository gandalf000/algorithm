#include <iostream>                                                                                     
#include <algorithm>                                                                                    
#include <unistd.h>

using namespace std;                                                                                    

int SimpleGetMaxPerimeter(int* data, int len) {                                                         
    int perimeter = 0;                                                                                  
    for (int i = 0; i < len; ++i) {                                                                     
        for (int j = i + 1; j < len; ++j) {                                                             
            for (int k = j + 1; k < len; ++k) {                                                         
                int sum = data[i] + data[j] + data[k];                                                  
                int max_edge = max(max(data[i], data[j]), data[k]);                                     
                if (sum - max_edge > max_edge) {                                                        
                    perimeter = max(sum, perimeter);                                                    
                }                                                                                       
            }                                                                                           
        }                                                                                               
    }                                                                                                   
    return perimeter;                                                                                   
}                                                                                                       

int* binary_search(int* left, int* right, int value) {                                                  
    while (left < right) {                                                                              
        int* middle = left + ((right - left + 1) >> 1);                                                 
        if (*middle >= value) {                                                                         
            right = middle - 1;                                                                         
        } else {                                                                                        
            left = middle;                                                                              
        }                                                                                               
    }                                                                                                   
    return left;          
}

int GetMaxPerimeter(int* data, int len) {                                                            
    int perimeter = 0;                                                                               
    std::sort(data, data+len);                                                                       
    for (int i = 0; i < len - 2; ++i) {                                                              
        for (int j = i + 1; j < len - 1; ++j) {                                                      
            int sum = data[i] + data[j];                                                             
            int* pos= binary_search(data + j + 1, data + len -1, sum);                               
            if (*pos < sum) {                                                                        
                perimeter = max(sum + *pos, perimeter);                                              
            }                                                                                        
        }                                                                                            
    }                                                                                                
    return perimeter;                                                                                
}                                                                                                    

int main(int argc, char** argv) {                                                                    
    srand(time(NULL));                                                                               
    while (true) {
        int number = rand() % 20 + 10;                                                                   
        int* data = (int*)malloc(sizeof(int) * number);                                                  
        for (int i = 0; i < number; ++i) {                                                               
            data[i] = rand() % 100 + 1;                                                                  
        }                                                                                                
        int result = SimpleGetMaxPerimeter(data, number);                                                
        if (result != GetMaxPerimeter(data, number)) {
            cerr << "triangle algorithm error"<< endl;
        } else {
            cout << "max perimeter:" << result << endl;                                                      
        }
        free(data);
        sleep(1);
    }
    return 0;
}
