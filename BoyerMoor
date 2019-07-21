#include <iostream>
#define n 16
#define m 5
using namespace std;

void Boyer_Moor(char *str, char *pattern, int *tbl);
void offset_table(int *tbl, char *pattern);
int findBM(char* str, char* pattern, int* tbl, int k);

template<typename S>
void show(S *a, int k){
    for(int i=0; i<k; i++) cout<<a[i]<<' ';
}

int main(){
    setlocale(LC_ALL, "rus");
    char str[n]={'q','w','t','e','e','q','e','w','q','r','w','q','w','w','q','r'};      //Строка
    char pattern[m]={'q', 'w', 'w', 'q', 'r'};                                          //Шаблон
    int *tbl = new int[m+1];                                                            //Таблица смещений
    cout<<"Строка: ";
    show(str, n);
    cout<<endl;
    cout<<"Шаблон: ";
    show(pattern, m);
    cout<<endl;
    offset_table(tbl, pattern);
    cout<<"Таблица смещения: ";
    show(tbl, m+1);
    cout<<endl;
    Boyer_Moor(str, pattern, tbl);
    cout<<endl;
    return 0;
}

void offset_table(int *tbl, char *pattern){             //Заполнение таблицы смещения
    tbl[m-2] = 1;                                       //|q|w|w|q|r|*|
    tbl[m] = m;                                         //|4|2|2|1|5|5|
    tbl[m-1] = m;
    for(int i=m-3 ; i>=0; i--){
        for(int j=i+1; j<=m-2; j++){
            if(pattern[i]==pattern[j]){
                tbl[i]=tbl[j];
                break;
            }
            else{
                tbl[i]= m-j;
                break;
            }
        }
    }

    for(int i=m-2; i>=0; i--){
        if(pattern[m-1]==pattern[i]){
            tbl[m-1]=tbl[i];
            break;
        }
    }
}

void Boyer_Moor(char *str, char *pattern, int *tbl){                                                      //Реализация алгоритма Бойера-Мура
    int c = 0;
    int cnt = 1;
    int i = 0;
    int j = 0;
    for(i = 0; i<n; i+=c){
        cnt=1;
        for(j=i+m-1; j>=0; j--){
            if(pattern[j]!=str[j]){
                c=findBM(str, pattern, tbl, j);
            }else cnt++;
        }
        if(cnt==m) break;
    }
    cout<<i<<endl;
    cout<<"Подстрока: ";
    for(int k = i+1; k<=i+m; k++) cout<<str[k]<<' ';
}

int findBM(char* str, char* pattern, int* tbl, int k){
    int i;
    for(i=m;i>=0&&str[k]==pattern[i];i--);
    if(i==-1) i = m;
    return tbl[i];
}
