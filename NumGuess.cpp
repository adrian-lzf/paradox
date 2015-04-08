#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int num1, num2, num3, ges1, ges2, ges3, A, B, i, win = 0, lose = 0;
    char stt; //determine whether to start
    
    while (stt =! 'Y' && stt =!'y' && stt =! 'N' && stt =!'n')
    {cout << "需要玩游戏吗（Y/N）？";
	cin >> stt;}
    while ((stt == 'Y') or (stt == 'y')) //let the game begin again if the user wants to
    {
		srand(time(NULL));
    	num1 = rand()%9+1; num2 = rand()%9+1; num3 = rand()%9+1; //form the numbers from 1 to 9
    	while (num2 == num1) num2 = rand()%9+1; //in case that num2 == num1
    	while (num3 == num2 or num3 == num1) num3 = rand()%9+1; //insure that the three numbers are all distinct
    	for(i=0; i<7; ++i){
        	A = B = 0;
        	cout << "请输入你猜测的数字: " << endl;
        	cin >> ges1 >> ges2 >> ges3;
        	if (ges1 == num1) A += 1; if (ges2 == num2) A += 1; if (ges3 == num3) A += 1; 
			//when the right number is in the right position, A += 1 
        	if (ges1 == num2 or ges1 == num3) B += 1;
        	if (ges2 == num1 or ges2 == num3) B += 1;
        	if (ges3 == num1 or ges3 == num2) B += 1;
        	//when the right number is in the wrong position, B += 1
        	if (A == 3){cout << "恭喜，你猜对了！" << endl; win += 1; break;}
        	else cout << A << "A" << B << "B" << endl;
        	if (i == 6){cout << "很遗憾，你没有在规定的次数内猜对。正确的答案是" << num1 << num2 << num3 << endl; lose += 1;}}
        do
        {cout << "需要玩游戏吗（Y/N）？";
		cin >> stt;} //the loop starts again
	while (stt =! 'Y' && stt =!'y' && stt =! 'N' && stt =!'n')
    }
    
	cout << "你一共玩了" << win + lose << "局，赢了" << win << "局，输了" << lose << "局"; //show the results
    return 0;

}
