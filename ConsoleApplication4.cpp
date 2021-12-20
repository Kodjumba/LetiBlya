
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <tuple>
#include <sstream>


using namespace std;

bool numbers(string str) {
    for (char a : str) {
        if (!isdigit(a) and a != '-') return false;
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
        //cout << m1;
        
    }
    file.close();
    return m1;
    
}



int** chitka(string filename, int n, int m) {
    fstream file;
    file.open("chunk/" + filename + ".txt", ios::in);
    if (!file.is_open()) {
        cout << ("Ошибка открытия файла");
        exit(1);
    }

    int** mas = new int* [n];
    int i = 0;
    string line;
    while (getline(file, line)) {
        int* stroka = new int[m];
        stringstream ss(line);

        int j = 0;
        string x;
        while (getline(ss, x, ' ')) {
            // cout << x << '#';
            if (j > m) break;
            stroka[j] = atoi(x.c_str());
            j++;
            
        }
        // cout << endl;

        mas[i] = stroka;
        i++;
    }
    return mas;
}


int summcheting(int** mas, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i=i+2) {
        for (int j = 0; j < m; j++) {
            // cout << i << endl;
            // cout << mas[i][j] << ' ';
            sum += mas[i][j];
        }
        // cout << endl;
    }
    return sum;
}


void desintegrate(int** mas, int sizen, int sizem) {
    for (int i = 0; i < sizen; i++) { 
            delete[] mas[i-1];
        
        
    }
    delete mas;
}


void printarr(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           // cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
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
    
    int** mas = chitka(filename, n, m);
    int sum = summcheting(mas, n, m);
    fstream file;
    file.open("out.txt", ios::out);
    file << "Изначальный массив:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file << mas[i][j] << ' ';
        }
        file << endl;
    }
    file << "Сумма: ";
    file << sum << endl;
    cout << sum << endl;
    desintegrate(mas, n, m);
}