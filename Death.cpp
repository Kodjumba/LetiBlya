#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <tuple>
#include <sstream>
#include <math.h>


using namespace std;

void desintegrate(double* mas, int sizen) {
    for (int i = 0; i < sizen; i++) {
        delete[] mas;


    }
    delete mas;
}
void desintegrate2(int* mas, int sizen) {
    for (int i = 0; i < sizen; i++) {
        delete[] mas;


    }
    delete mas;
}
void desintegrate1(double** mas, int sizen) {
    for (int i = 0; i < sizen; i++) {
        delete[] mas;


    }
    delete mas;
}
bool numbers(string str) {
    for (char a : str) {
        if (!isdigit(a)) return false;
    }
    return true;
}

int sizen(string arrayname) {
    fstream file;
    file.open("chunk/" + arrayname + ".txt", ios::in);
    if (!file.is_open()) {
        cout << "2Ошибка открытия файла";
        exit(1);
    }
    string line;
    int n = 0;

    while (getline(file, line)) {
        if (line.length() != 0) {
            n++;
        }
    }

    file.close();
    return n;
}

int sizem(string arrayname, int n) {
    fstream file;
    file.open("chunk/" + arrayname + ".txt", ios::in);
    if (!file.is_open()) {
        cout << "1Ошибка открытия файла";
        exit(1);
    }
    string line;
    int m = 0;
    //getline(file, line);

    //int a = n;
    //int ncount=0;
    string x;
    int m1 = numeric_limits<int>::max();
    while (getline(file, line)) {
        stringstream ss(line);
        m = 0;
        //if (file.eof() == true) break;
        while (getline(ss, x, ' ')) {
            m++;
            
            //if (file.eof()==true) break;
            //ncount++;
        }
        if (m < m1) m1 = m;
        if (m1 == 3) {
            cout << "Ошибка: задана неверная координата";
            exit(1);
        }

    }
    file.close();
    return m1;

}



double ** chitka(string filename, int n, int m) {
    fstream file;
    file.open("chunk/" + filename + ".txt", ios::in);
    if (!file.is_open()) {
        cout << ("Ошибка открытия файла");
        exit(1);
    }

    double** mas = new double* [n];
    int i = 0;
    string line;
    while (getline(file, line)) {
        double* stroka = new double[m];
        stringstream ss(line);

        int j = 0;
        string x;
        while (getline(ss, x, ' ')) {
            // cout << x << '#';
            if (j > m) break;
            stroka[j] = atof(x.c_str());
            j++;

        }
        // cout << endl;

        mas[i] = stroka;
        i++;
    }
    return mas;
}


/*int sqrt(int a) {
    int r = pow(a, 1 / 2);
    return r;
    

}*/
int findminx(double* arrx){
    int min = numeric_limits<int>::max();
    for (unsigned i = 0; i < 4; i++) {
        if (min > arrx[i]) min = arrx[i];
    }
    return min;
}
int findmaxx(double* arrx) {
    int max=0;
    
    for (unsigned i = 0; i < 4; i++) {
        if (max < arrx[i]) max = arrx[i];
       
        
    }
    
    return max;
}


bool check(double* arrx, double* arry) {
    bool TrueCounter=false;
    
    
    if (((arrx[0] - arrx[2]) * (arry[1] - arry[2]) - (arrx[1] - arrx[2]) * (arry[0] - arry[2]) == 0) &&\
        ((arrx[1] - arrx[3]) * (arry[2] - arry[3]) - (arrx[2] - arrx[3]) * (arry[1] - arry[3]) == 0)) {
         TrueCounter=true;
         
           
    }
        
    if (TrueCounter == true) {
        if (sqrt((arrx[1] - arrx[0]) * (arrx[1] - arrx[0]) + (arry[1] - arry[0]) * (arry[1] - arry[0])) \
            == sqrt((arrx[3] - arrx[2]) * (arrx[3] - arrx[2]) + (arry[3] - arry[2]) * (arry[3] - arry[2])) || \
            sqrt((arrx[3] - arrx[1]) * (arrx[3] - arrx[1]) + (arry[3] - arry[1]) * (arry[3] - arry[1])) \
            == sqrt((arrx[2] - arrx[0]) * (arrx[2] - arrx[0]) + (arry[2] - arry[0]) * (arry[2] - arry[0]))) {
            bool absos = true;
            return true;
        }
           
        
    }
    /*else {
        cout << "not work" << endl;
        return false;
    }
    */
    }


bool peremoga(double** mas, int n, int m, int i) {
    double* arrx = new double[4];
    double* arry = new double[4];
    int j = 0;
    for (i; i < n-3 ; i++) {
        cout << "i " << i << endl;
        for (int o = 1 + i; o < n-2; o++) {
            cout << "o " << o << endl;

            for (int p = 2 + i; p < n-1; p++) {
                cout << "p " << p << endl;

                for (int x = 3+i; x < n; x++) {
                    cout << "x " << x << endl;

                    if ((mas[p][j] - mas[i][j]) * (mas[o][j + 1] - mas[i][j + 1] - ((mas[o][j] - mas[i][j]) * (mas[p][j + 1] - mas[i][j + 1]))==0\
                        && (mas[x][j] - mas[i][j]) * (mas[o][j + 1] - mas[i][j + 1]) - ((mas[o][j] - mas[i][j]) * (mas[x][j + 1] - mas[i][j + 1])))==0 && i!=o!=p!=x)
                    {
                       // cout << "mas" << mas[o][j + 1];
                        arrx[0] = mas[i][j];
                        arrx[1] = mas[o][j];
                        arrx[2] = mas[p][j];
                        arrx[3] = mas[x][j];
                        arry[0] = mas[i][j+1];
                        arry[1] = mas[o][j+1];
                        arry[2] = mas[p][j+1];
                        arry[3] = mas[x][j+1];
                        break;
                        //cout << "x1 " << arrx[0] << endl;
                        //cout << "x2 " << arrx[1] << endl;
                        //cout << "x3 " << arrx[2] << endl;
                        //cout << "x4 " << arrx[3] << endl;
                        //cout << "y1 " << arry[0] << endl;
                        //cout << "y2 " << arry[1] << endl;
                        //cout << "y3 " << arry[2] << endl;
                        //cout << "y4 " << arry[3] << endl;
                        
                    }
                }
            }
        }
    }
    if (check(arrx, arry)) {
        return true;
    }
 
}

           
       
    
            
            
        
    

double* peremogax(double** mas, int n, int m, int i) {
    double* arrx = new double[4];
    int j = 0;
    for (i; i < n-3; i++) {
        for (int o = 1 + i; o < n-2; o++) {
            for (int p = 2 + i; p < n-1; p++) {
                for (int x = 3 + i; x < n; x++) {
                    if ((mas[p][j] - mas[i][j]) * (mas[o][j + 1] - mas[i][j + 1] - ((mas[o][j] - mas[i][j]) * (mas[p][j + 1] - mas[i][j + 1])) == 0\
                        && (mas[x][j] - mas[i][j]) * (mas[o][j + 1] - mas[i][j + 1]) - ((mas[o][j] - mas[i][j]) * (mas[x][j + 1] - mas[i][j + 1]))) == 0 && i!=o!=p!=x)
                    {
                        // cout << "mas" << mas[o][j + 1];
                        arrx[0] = mas[i][j];
                        arrx[1] = mas[o][j];
                        arrx[2] = mas[p][j];
                        arrx[3] = mas[x][j];
                        break;
                    }
                }
            }
        }
    }
                        
    
    return arrx;
    desintegrate(arrx, 4);
}
double* peremogay(double **mas, int n, int m, int i) {
    double* arry = new double[4];
    for (i; i < n-3; i++) {
        int j = 0;
        for (int o = 1 + i; o < n-2; o++) {
            for (int p = 2 + i; p < n-1; p++) {
                for (int x = 3 + i; x < n; x++) {

                    if ((mas[p][j] - mas[i][j]) * (mas[o][j + 1] - mas[i][j + 1] - ((mas[o][j] - mas[i][j]) * (mas[p][j + 1] - mas[i][j + 1])) == 0\
                        && (mas[x][j] - mas[i][j]) * (mas[o][j + 1] - mas[i][j + 1]) - ((mas[o][j] - mas[i][j]) * (mas[x][j + 1] - mas[i][j + 1]))) == 0 && i!=o!=p!=x)
                    {
                       // cout << "mas" << mas[o][j + 1];
                        arry[0] = mas[i][j + 1];
                        arry[1] = mas[o][j + 1];
                        arry[2] = mas[p][j + 1];
                        arry[3] = mas[x][j + 1];
                        break;
                    }
                }
            }
        }
    
    }
    return arry;
    desintegrate(arry, 4);
}
int ihatenmax(int max, double* arrx) {
    int n = 0;
    
    for (unsigned i = 0; i < 4; i++) {
        //cout << "a" << arrx[i] << endl;
        if (max == arrx[i]) n = i;
        
    }
    //cout << "n=" << n << endl;
    return n;
}
int ihatenmin(int min, double* arrx) {
    int n = 0;
    for (unsigned i = 0; i < 4; i++) {
        if (min == arrx[i]) n = i;

    }
    return n;
}
int bruhtella(int n, int m, double* arrx) {
    int nn=0;
    for (int i = 0; i < 4; i++) {
        if (arrx[i] != n && arrx[i] != m) {
            
            nn = arrx[i];
            
        }
    }
    return nn;

}
int bruhtellanum(int n, int m, int k, double* arrx) {
    int nn = 0;
    int a=0;
    for (int i = 0; i < 4; i++) {
        if (arrx[i] == k) a = i;
        
        
    }
    
    return a;
}
double findcentreandraduism(int mid, int min, int max, double* arrx, double* arry) {
    
    int xcen = ((arrx[max] + arrx[min]) / 2);
    double ycen = ((arry[max] + arry[min]) / 2);
    double mradius = sqrt(((arrx[mid] - xcen) * (arrx[mid] - xcen)) + ((arry[mid] - ycen) * (arry[mid] - ycen)));
    return mradius;
    






}
double findcentreandraduisM(int mid, int min, int max, double* arrx, double* arry) {
    double xcen = ((arrx[max] + arrx[min]) / 2);
    double ycen = ((arry[max] + arry[min]) / 2);
    double Mradius = sqrt(((arrx[max] - xcen) * (arrx[max] - xcen)) + ((arry[max] - ycen) * (arry[max] - ycen)));
    return Mradius;
}

int prinadleshnost(double** mas, double r, double R, int n, double* arrx, double* arry) {
    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        //y=-(x1y2-x2y1)-(y1-y2)x/(x2-x1)
        double a = ((mas[i][j] * mas[i][j]) + (mas[i][j + 1] * mas[i][j + 1]));
       // cout << a << "r" << r << endl;
       // cout << a << "R" << R << endl;
        //cout << "y" << (arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] << endl;
        if (a > r*r && a < R*R && ((arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] > 0)){
            //cout << mas[i][j + 1];
            count++;
                
                
                
            }
        
    }
    
    return count;
   
}
int prinadleshnost1(double** mas, double r, double R, int n, double* arrx, double* arry) {
    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        //y=-(x1y2-x2y1)-(y1-y2)x/(x2-x1)
        double a = ((mas[i][j] * mas[i][j]) + (mas[i][j + 1] * mas[i][j + 1]));
        // cout << a << "r" << r << endl;
        // cout << a << "R" << R << endl;
         //cout << "y" << (arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] << endl;
        if (a > r*r && a < R*R && ((arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] < 0)) {
            //cout << mas[i][j + 1];
            count++;



        }

    }

    return count;

}
int* prinadleshnosttocka(double** mas, double r, double R, int n, double* arrx, double* arry, int count) {
    int j = 0;
    int k = 0;
    int* mass = new int[count];
    for (int i = 0; i < n; i++) {
        //y=-(x1y2-x2y1)-(y1-y2)x/(x2-x1)
        double a = ((mas[i][j] * mas[i][j]) + (mas[i][j + 1] * mas[i][j + 1]));
        // cout << a << "r" << r << endl;
         //cout << a << "R" << R << endl;
        // cout << "y" << (arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] << endl;
        if (a > r*r && a < R*R && ((arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] > 0)) {
            
            
            mass[k] = i;
            
            k++;


        }
        

    }
    return mass;
    desintegrate2(mass, count);
    

}
int* prinadleshnosttocka1(double** mas, double r, double R, int n, double* arrx, double* arry, int count) {
    int j = 0;
    int k = 0;
    int* mass = new int[count];
    for (int i = 0; i < n; i++) {
        //y=-(x1y2-x2y1)-(y1-y2)x/(x2-x1)
        double a = ((mas[i][j] * mas[i][j]) + (mas[i][j + 1] * mas[i][j + 1]));
        // cout << a << "r" << r << endl;
         //cout << a << "R" << R << endl;
        // cout << "y" << (arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] << endl;
        if (a > r*r && a < R*R && ((arry[0] - arry[1]) * mas[i][j] + (arrx[0] * arry[1] - arrx[1] * arry[0]) + (arrx[1] - arrx[0]) * mas[i][j + 1] < 0)) {


            mass[k] = i;

            k++;


        }


    }
    return mass;
    desintegrate2(mass, count);


}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Автор: Безруков Павел \n"
        "Группа: 1302 \n"
        "Дата начала: 26.11.2021 \n"
        "Дата конца: 26.11.2021 \n"
        "Версия: 5.0.0 \n" << endl;

    string filename = "A";
    int n = sizen(filename);
    int m = sizem(filename, n);
    double** mas = chitka(filename, n, m);
    double* arrx = new double[4];
    double* arry = new double[4];
    int count1 = 0;
    int raduga1 = 0;
    int raduga = 0;
    double r1 = 0;
    double R1 = 0;
    double* arrx1 = new double[4];
    double* arry1 = new double[4];
    bool up = false;
    //cout << n << endl;
    fstream file;
    
    file.open("out.txt", ios::out);
    for (int i = 0; i < n; i++) {
        //  cout << peremoga(mas, n, m, i);
        int k = 0;
        //cout << i << endl;
        if (peremoga(mas, n, m, i) == true) {
            raduga1++;

            cout << "Существует нужная нам фигура " << raduga1 << " из точек:" << endl;
            cout << "| " << " x " << " | " << " y " << " |" << endl;
            file << "Существует нужная нам фигура " << raduga1 << " из точек:" << endl;
            file << "| " << " x " << " | " << " y " << " |" << endl;
            arrx = peremogax(mas, n, m, i);
            arry = peremogay(mas, n, m, i);
            for (int d = 0; d < 4; d++) {
                cout << "| " << arrx[d] << " | " << arry[d] << " |" << endl;
                file << "| " << arrx[d] << " | " << arry[d] << " |" << endl;
            }

            int max = findmaxx(arrx);
            int min = findminx(arrx);
            int ny = ihatenmax(max, arrx);
            int nyx = ihatenmin(min, arrx);
            int mid = bruhtella(max, min, arrx);
            int nyxmid = bruhtellanum(ny, nyx, mid, arrx);


            double r = findcentreandraduism(nyxmid, nyx, ny, arrx, arry);
            double R = findcentreandraduisM(nyxmid, nyx, ny, arrx, arry);

            int count = prinadleshnost(mas, r, R, n, arrx, arry);
            int count2 = prinadleshnost1(mas, r, R, n, arrx, arry);
            //cout << "c=" << count;
            if (count1 < count) {
                up = true;
                count1 = count;
                raduga = raduga1;
                r1 = r;
                R1 = R;
                arrx1 = arrx;
                arry1 = arry;
            }
            if (count1 < count2) {
                up = false;
                count1 = count2;
                raduga = raduga1;
                r1 = r;
                R1 = R;
                arrx1 = arrx;
                arry1 = arry;
            }




            cout << "Фигура " << raduga1 << ",направленная вверх, содержит " << count << " точку/точек" << endl;
            cout << "Фигура " << raduga1 << ",направленная вниз, содержит " << count2 << " точку/точек" << endl;
            file << "Фигура " << raduga1 << ",направленная вверх, содержит " << count << " точку/точек" << endl;
            file << "Фигура " << raduga1 << ",направленная вниз, содержит " << count2 << " точку/точек" << endl;
            if (count != 0) {
                int* dots = prinadleshnosttocka(mas, r, R, n, arrx, arry, count);
                int* dotsdown = prinadleshnosttocka1(mas, r, R, n, arrx, arry, count1);
                cout << "точки вверху:" << endl;
                cout << "| " << " x " << " | " << " y " << " |" << endl;
                file << "точки вверху:" << endl;
                file << "| " << " x " << " | " << " y " << " |" << endl;
                for (int p = 0; p < count1; p++) {
                    k = dots[p];
                    //cout << k << endl;
                    cout << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;
                    file << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;

                }
            }
            if (count2 != 0) {
                int* dotsdown = prinadleshnosttocka1(mas, r, R, n, arrx, arry, count1);
                cout << "точки внизу:" << endl;
                cout << "| " << " x " << " | " << " y " << " |" << endl;
                file << "точки внизу:" << endl;
                file << "| " << " x " << " | " << " y " << " |" << endl;
                for (int p = 0; p < count1; p++) {
                    k = dotsdown[p];
                    //cout << k << endl;
                    cout << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;
                    file << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;

                }
            }
        }
    }

        /*else {
            cout << "Error: No spots\n";
        }
        */

    if (up) {
        cout << "Фигура " << raduga << ",направленная вверх, содержит больше всего точек, а именно " << count1 << endl;
        cout << "Точки:" << endl;
        file << "Фигура " << raduga << ",направленная вверх, содержит больше всего точек, а именно " << count1 << endl;
        file << "Точки:" << endl;
        int* dots = prinadleshnosttocka(mas, r1, R1, n, arrx1, arry1, count1);
        for (int i = 0; i < count1; i++) {
            int k = dots[i];
            //cout << dots[i] << endl;
            cout << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;
            file << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;
        }
    }
    else if (!up) {
        cout << "Фигура " << raduga << ",направленная вниз, содержит больше всего точек, а именно " << count1 << endl;
        cout << "Точки:" << endl;
        file << "Фигура " << raduga << ",направленная вниз, содержит больше всего точек, а именно " << count1 << endl;
        file << "Точки:" << endl;
        int* dots = prinadleshnosttocka1(mas, r1, R1, n, arrx1, arry1, count1);
        for (int i = 0; i < count1; i++) {
            int k = dots[i];
            //cout << dots[i] << endl;
            cout << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;
            file << "| " << mas[k][0] << " | " << mas[k][1] << " |" << endl;
        }
    }

    desintegrate(arrx, 4);
    desintegrate(arrx, 4);
    desintegrate1(mas, n);
    //desintegrate2(dots, count1);
    //cout << count1;
}