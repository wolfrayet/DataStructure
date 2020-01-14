//  Data Structure
//  Yu-Hsiu Huang   104061249
//  2018/06/04
#include <iostream>
#include <iomanip>
#include <string>
#define H	1.00
#define He	4.00
#define Li	7.00
#define Be	9.00
#define B	11.00
#define C	12.00
#define N	14.00
#define O	16.00
#define F	19.00
#define Ne	20.00
#define Na	23.00
#define Mg	24.00
#define Al	27.00
#define Si	28.00
#define P	31.00
#define S	32.00
#define Cl	35.00
#define Ar	40.00
#define K	39.00
#define Ca	40.00
#define Sc	45.00
#define Ti	48.00
#define V	51.00
#define Cr	52.00
#define Mn	55.00
#define Fe	56.00
#define Co	59.00
#define Ni	59.00
#define Cu	64.00
#define Zn	65.00
#define Ga	70.00
#define Ge	73.00
#define As	75.00
#define Se	79.00
#define Br	80.00
#define Kr	84.00
#define Rb	85.00
#define Sr	88.00
#define Y	89.00
#define Zr	91.00
#define Nb	93.00
#define Mo	96.00
#define Tc	97.00
#define Ru	101.00
#define Rh	103.00
#define Pd	106.00
#define Ag	108.00
#define Cd	112.00
#define In	115.00
#define Sn	119.00
#define Sb	122.00
#define Te	128.00
#define I	127.00
#define Xe	131.00
#define Cs	133.00
#define Ba	137.00
#define La	139.00
#define Ce	140.00
#define Pr	141.00
#define Nd	144.00
#define Pm	145.00
#define Sm	150.00
#define Eu	152.00
#define Gd	157.00
#define Tb	159.00
#define Dy	163.00
#define Ho	165.00
#define Er	167.00
#define Tm	169.00
#define Yb	173.00
#define Lu	175.00
#define Hf	178.00
#define Ta	181.00
#define W	184.00
#define Re	186.00
#define Os	190.00
#define Ir	192.00
#define Pt	195.00
#define Au	197.00
#define Hg	201.00
#define Tl	204.00
#define Pb	207.00
#define Bi	209.00
#define Po	209.00
#define At	210.00
#define Rn	222.00
#define Fr	223.00
#define Ra	226.00
#define Ac	227.00
#define Th	232.00
#define Pa	231.00
#define U	238.00
#define Np	237.00
#define Pu	244.00
#define Am	243.00
#define Cm	247.00
#define Bk	247.00
#define Cf	251.00
#define Es	252.00
#define Fm	257.00
#define Md	258.00
#define No	259.00
#define Lr	262.00
#define Rf	267.00
#define Db	270.00
#define Sg	269.00
#define Bh	270.00
#define Hs	270.00
#define Mt	278.00
#define Ds	281.00
#define Rg	281.00
#define Cn	285.00
#define Nh	286.00
#define Fl	289.00
#define Mc	289.00
#define Lv	293.00
#define Ts	293.00
#define Og	294.00
using namespace std;
class Mole
{
    public:
        Mole() {}
        void Create(string t1, string t2, double t3) {
            name=t1;
            formula=t2;
            mass=t3;
        }
        void MoleMass();
        int getSizeName() {return name.size();}
        int getSizeFormula() {return formula.size();}
        int getSizeMass() {
            if (mass<10) return 4;
            else if (mass<100) return 5;
            else if (mass<1000) return 6;
            else return 7;
        }
        string name;
        string formula;
        double mass;
};
void QuickSort(Mole *m, const int up, const int down, int &step)
{
    if (up<down) {
        Mole &pivot=m[up];
        int i=up;
        int j=down+1;
        do {
            do j--; while (m[j].mass>pivot.mass && j>0);
            do { i++;} while (i<j && m[i].mass<=pivot.mass);
            if (i<j) { 
                if (m[i].mass != m[j].mass) {
                    swap(m[i],m[j]);
                    step++;
                }
            }
        } while(i<j);
        if (pivot.mass != m[j].mass) {
            swap(pivot, m[j]);
            step++;
        }
        QuickSort(m, up, j-1, step);
        QuickSort(m, j+1, down, step);
    }
}
void Output(Mole *m, const int amount, const int step)
{
    for (int i=0; i<amount; i++) {
        int length;
        cout << m[i].name;
        length=40-m[i].getSizeName();
        for (int j=0; j<length; j++) cout << " ";
        cout << m[i].formula;
        length=25-m[i].getSizeFormula();
        for (int j=0; j<length; j++) cout << " ";
        length=10-m[i].getSizeMass();
        for (int j=0; j<length; j++) cout << " ";
        cout << fixed << setprecision(2)<< m[i].mass;
        cout << endl;
    }
    cout << step << " swaps during qsort" <<endl;
}
int main(void) 
{
    int num;
    int amount;
    int step;
    string temp1;
    string temp2;
    double temp3;
    cin >> num;
    cout << num << endl;
    for (int i=0; i<num; i++) {
        step=0;
        cin >> amount;
        cout << amount << endl;
        Mole *m = new Mole[amount];
        for (int j=0; j<amount ;j++) {
            cin >> temp1 >> temp2 >> temp3;
            m[j].Create(temp1, temp2, temp3);
            if (temp3 == 0) m[j].MoleMass();
        }
        QuickSort(m, 0, amount-1, step);
        Output(m, amount, step);
        delete [] m;
    }
    return 0;
}
void Mole::MoleMass()
{
    string temp;
    int i=0;
    while (i<getSizeFormula()) {
        if (formula[i]!=40 && formula[i]!=41 && formula[i]!=91 && formula[i]!=93) {
            if (formula[i+1]>=65 && formula[i+i]<=90) {
                i++;
                if (formula[i+1]>=49 && formula[i+i]<=57) {
                    i++;
                }
            }
            else if (formula[i+1]>=97 && formula[i+i]<=122) {
                i+=2;
                temp=formula[i]+formula[i+1];
            }
        }
    }
}
