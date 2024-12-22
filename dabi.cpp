#include <bits/stdc++.h>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;


const double treedam=2.5;
const double daodam=1;
const double csdef=7;
const double cszldef=4;
const double hui_per_yd=1.5;

double zan[2],dabi[2],fdun[2],ydun[2];
double hp[2]={1.5,1.5};
double treetimes[2],daotimes[2],dealtdamage[2];
map <char,bool> ban[2];//蜜汁叉烧饭 
char cz,cztmp[2];
string yingkongcin,dealtdamagemsg;
bool ifcszl[2];
int lstcs[2]={-2,-2},lstkong[2]={-100,-100};
int rounds=0,cstimes[2];
bool chu=0,caozuoing;//0蓝方，1红方
string leftmsg[3];
map <char,string> mpmove;
vector<string> tips;

int how_digit(double a){
	string tmp=to_string(a);
	//cout<<"tmp="<<tmp<<endl;
	for(int i=tmp.length()-1;i>=0;i--){
		if(tmp[i]=='.') return (i-1)+1;
		if(tmp[i]!='0') return i+1;	
		//+1：下标 
	}
} 
void qp(){
	system("cls");
	return;
}
string a(bool x){
	if(x==0) return "蓝方";
	else return "红方"; 
}
bool ifhefa(char c,bool b){
	if(c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='q' && c!='w' && c!='e' && c!='a' && c!='s' && c!='d' && c!='z' && c!='x' && c!='0' && c!='/'){
		return 0;
	}
	if(c=='a' && zan[b]<1 && dabi[b]<1) return 0;
	if(c=='s' && dabi[b]<1) return 0;
	if(cztmp[b]=='z' && rounds-lstcs[b]<=1) return 0;
	if(cztmp[b]=='x' && cstimes[b]<2) return 0;
	if(cztmp[b]=='0' && rounds-lstkong[b]<=10) return 0;
	if(ban[b][c]==1) return 0;
	return 1;
}
bool ifhefatimes(int c){
	if(1<=c && c<=4){
		return 1;
	}
	return 0;
}
char read(){
	while(1){
		if(_kbhit()){
			char tempp = _getch();
			return tempp;
		}
	}
}
/*	
string num_to_hanzi(int a){
	if(a==1){
		return "一";
	}else if(a==2){
		return "二";
	}else if(a==3){
		return "三";
	}else if(a==4){
		return "四";
	}else if(a==5){
		return "五";
	}else if(a==6){
		return "六";
	}else{
		return "代码出Bug了？";
	}
}
void yingkong(int times,bool a){
	if(a==0){
		cout<<"对方已经被硬控！请输入"<<num_to_hanzi(times)<<"个字符，代表"<<num_to_hanzi(times)<<"次操作。"<<endl;
		cin>>yingkongcin;
		if(yingkongcin.length()>times) cout<<"次数超过"<<times<<"，自动截取前"<<num_to_hanzi(times)<<"个字符。"<<endl;
		for(int i=0;i<times;i++){
			caozuo(yingkongcin[i],1,chu);
		}
	}else{
		cout<<"你已经被硬控！请对方输入"<<num_to_hanzi(times)<<"个字符，代表"<<num_to_hanzi(times)<<"次操作。"<<endl;
		cin>>yingkongcin;
		if(yingkongcin.length()>times) cout<<"次数超过"<<times<<"，自动截取前"<<num_to_hanzi(times)<<"个字符。"<<endl;
		for(int i=0;i<times;i++){
			caozuo(yingkongcin[i],1,!chu);
		}
	}
	Sleep(600);
	return;
}
*/
void upd(){
	qp();
	int lantotlength1=26+how_digit(zan[0])+how_digit(dabi[0])+how_digit(ydun[0])+how_digit(fdun[0]);
	int hongtotlength1=26+how_digit(zan[1])+how_digit(dabi[1])+how_digit(ydun[1])+how_digit(fdun[1]);
	int totlength2=18+how_digit(hp[0])+how_digit(hp[1]);
	int lantotlength2=5;
	int hongtotlength2=4;
	string lanbannedlist="禁：";
	string hongbannedlist="禁：";
	
	for(auto it=ban[0].begin();it!=ban[0].end();it++){
		if((it->second)==1){
			lantotlength2+=3;
			lanbannedlist+=mpmove[it->first].substr(0,2);
			lanbannedlist+=" ";
		}
	}
	for(auto it=ban[1].begin();it!=ban[1].end();it++){
		if((it->second)==1){
			hongtotlength2+=3;
			hongbannedlist+=mpmove[it->first].substr(0,2);
			hongbannedlist+=" ";
		}
	}
	//cout<<lantotlength2<<endl;
	cout<<"-------------------蓝方--------------------------------------红方-------------------"<<endl;
	
	cout<<"| 攒："<<zan[0]<<" 搭鼻："<<dabi[0]<<" 圆盾："<<ydun[0]<<" 方盾："<<fdun[0];
	for(int i=1;i<=40-lantotlength1;i++) cout<<" ";
	cout<<"|";
	for(int i=1;i<=40-hongtotlength1;i++) cout<<" ";
	cout<<" 攒："<<zan[1]<<" 搭鼻："<<dabi[1]<<" 圆盾："<<ydun[1]<<" 方盾："<<fdun[1];
	cout<<"|"<<endl;
	
	cout<<"| 蓝方HP："<<hp[0]<<" 红方HP："<<hp[1];
	for(int i=1;i<=40-totlength2;i++) cout<<" ";
	cout<<"|";
	for(int i=1;i<=40-totlength2;i++) cout<<" ";
	cout<<" 蓝方HP："<<hp[0]<<" 红方HP："<<hp[1];
	cout<<"|"<<endl;
	
	cout<<"| "<<lanbannedlist;
	for(int i=1;i<=40-lantotlength2;i++) cout<<" ";
	cout<<"|";
	for(int i=1;i<=40-hongtotlength2;i++) cout<<" ";
	cout<<hongbannedlist;
	cout<<"|"<<endl;
	
	if(caozuoing){
		if(chu==1){
			cout<<"|";
			for(int i=1;i<=12;i++) cout<<" ";
			cout<<"您目前不能操作！";
			for(int i=1;i<=12;i++) cout<<" ";
			cout<<"|";
			for(int i=1;i<=40;i++) cout<<" ";
			cout<<"|"<<endl;
		}else{
			cout<<"|";
			for(int i=1;i<=40;i++) cout<<" ";
			cout<<"|";
			for(int i=1;i<=12;i++) cout<<" ";
			cout<<"您目前不能操作！";
			for(int i=1;i<=12;i++) cout<<" ";
			cout<<"|"<<endl;
		}
	}else{
		cout<<"|";
		for(int i=1;i<=40;i++) cout<<" ";
		cout<<"|";
		for(int i=1;i<=40;i++) cout<<" ";
		cout<<"|"<<endl;
	}
	

	cout<<"-------------------蓝方--------------------------------------红方-------------------"<<endl;
	cout<<"操作方法："<<endl;
	cout<<"1:攒 2:搭鼻 3:圆盾 4:方盾 5:上盾"<<endl;
	cout<<"q:兵粮寸断！ w:水土不服！e:翻倍！"<<endl;
	cout<<"a:锤! s:刀！d:蜜汁叉烧饭！"<<endl;
	cout<<"z:超闪！ x:超闪之力！ 0:空 /：认输！"<<endl;
	return;
}
//0 41 82
void updmove(char a,char b){
	string ans[110];
	string movea=mpmove[a];
	string moveb=mpmove[b];
	string tmp="！"; 
	int lena=movea.length()/2;//字数 
	int lenb=moveb.length()/2;//字数 
	for(int i=1;i<=100;i++){
		ans[i]="                                                                                                    ";
	}
	if(lena<=lenb){
		//  方|方
		//方盾|方盾 
		for(int i=1;i<=lena;i++){
			for(int j=1;j<=i;j++){
				ans[i][41+j*2-1]=moveb[(j-1)*2];
				ans[i][41+j*2]=moveb[(j-1)*2+1];
			}
			for(int j=i;j>=1;j--){
				ans[i][41-j*2]=movea[(i-j+1-1)*2];
				ans[i][41-j*2+1]=movea[(i-j+1-1)*2+1];
			}
			ans[i][41]='|';
		}
		for(int i=lena+1;i<=lenb;i++){
			ans[i]=ans[lena];
			for(int j=lena+1;j<=i;j++){
				ans[i][41+j*2-1]=moveb[(j-1)*2];
				ans[i][41+j*2]=moveb[(j-1)*2+1];
			}
			ans[i][41]='|';
		}
	}else{
		//lenb<lena
		//兵粮寸断
		//搭鼻
		//      兵|搭
		//    兵粮|搭鼻
		//  兵粮寸|搭鼻 
		//兵粮寸断|搭鼻 
		for(int i=1;i<=lenb;i++){
			for(int j=1;j<=i;j++){
				ans[i][41+j*2-1]=moveb[(j-1)*2];
				ans[i][41+j*2]=moveb[(j-1)*2+1];
			}
			for(int j=1;j<=i;j++){
				ans[i][41-j*2]=movea[(i-j+1-1)*2];
				ans[i][41-j*2+1]=movea[(i-j+1-1)*2+1];
			}
			ans[i][41]='|';
		}
		for(int i=lenb+1;i<=lena;i++){
			for(int j=1;j<=i;j++){
				ans[i][41-j*2]=movea[(i-j+1-1)*2];
				ans[i][41-j*2+1]=movea[(i-j+1-1)*2+1];
			}
			for(int j=1;j<=lenb;j++){
				ans[i][41+j*2-1]=moveb[(j-1)*2];
				ans[i][41+j*2]=moveb[(j-1)*2+1];
			}
			ans[i][41]='|';
		}
		
	}
	//这坨代码就是能跑的答辩 
	for(int i=1;i<=max(lena,lenb);i++){
		upd(); 
		cout<<ans[i]<<endl;
		Sleep(300);
	}
	return;
}
void caozuo(char ch,bool ykmode,bool chu){
	if(ch=='1'){
		zan[chu]++;
	}else if(ch=='2'){
		dabi[chu]++;
	}else if(ch=='3'){
		ydun[chu]++;
	}else if(ch=='4'){
		if(ykmode){
			
		}else{
			fdun[chu]++;
		}
	}else if(ch=='5'){
		if(ydun[chu]==0){
			leftmsg[chu]="没有圆盾！";
		}else{
			hp[chu]+=ydun[chu]*hui_per_yd;
			ydun[chu]=0;
			Sleep(400);
		}
		
	}else if(ch=='q'){
		if(ykmode){
			
		}else if(cztmp[!chu]=='0'){
			fdun[chu]--;
			leftmsg[chu]="随着一声'空'，你的硬控被防住了！";
		}else if(cztmp[!chu]=='z'){
			fdun[chu]--;
			leftmsg[chu]="随着一声'超闪'，你的硬控被防住了！";
		}else if(ifcszl[!chu] || cztmp[!chu]=='x'){
			fdun[chu]--;
			leftmsg[chu]="随着一声'超闪之力'，你的硬控被防住了！";
		}else if(cztmp[!chu]=='q'){
			fdun[chu]--;
			leftmsg[2]="两个硬控互相抵消！";
		}else if(cztmp[!chu]=='w'){
			fdun[chu]--;
			cout<<"两个硬控互相抵消，"<<a(chu)<<"被硬控两次！"<<endl;
			cout<<a(chu)<<"已经被硬控！请对方输入两个字符，代表两次操作。"<<endl;
			cin>>yingkongcin;
			if(yingkongcin.length()>2) cout<<"次数超过2，自动截取前两个字符。"<<endl;
			for(int i=0;i<2;i++){
				caozuo(yingkongcin[i],1,!chu);
			}
		}else if(fdun[chu]<1){
			cout<<"方盾不够！"<<endl;
			Sleep(400);
		}else{
			fdun[chu]--;
			cout<<a(!chu)<<"已经被硬控！请"<<a(chu)<<"输入三个字符，代表三次操作。"<<endl;
			cin>>yingkongcin;
			if(yingkongcin.length()>3) cout<<"次数超过3，自动截取前三个字符。"<<endl;
			for(int i=0;i<3;i++){
				caozuo(yingkongcin[i],1,chu);
			}
		}
	}else if(ch=='w'){
		if(ykmode){
	
		}else if(cztmp[!chu]=='0'){
			fdun[chu]-=2;
			leftmsg[chu]="随着一声'空'，你的硬控被防住了！";
		}else if(cztmp[!chu]=='z'){
			fdun[chu]-=2;
			cout<<"随着一声'超闪'，你的硬控被防住了！"<<endl; 
		}else if(ifcszl[!chu] || cztmp[!chu]=='x'){
			fdun[chu]-=2;
			cout<<"随着一声'超闪之力'，你的硬控被防住了！"<<endl;
		}else if(cztmp[!chu]=='q'){
			fdun[chu]-=2;//和蓝q红w重复 
		}else if(cztmp[!chu]=='w'){
			fdun[chu]-=2;
			leftmsg[2]="两个硬控互相抵消！";
		}else if(fdun[chu]<2){
			cout<<"方盾不够！"<<endl;
			Sleep(400);
		}else{
			fdun[chu]-=2;
			cout<<a(!chu)<<"已经被硬控！请"<<a(chu)<<"输入五个字符，代表五次操作。"<<endl;
			cin>>yingkongcin;
			if(yingkongcin.length()>5) cout<<"次数超过5，自动截取前五个字符。"<<endl;
			for(int i=0;i<5;i++){
				caozuo(yingkongcin[i],1,chu);
			}
		}
	}else if(ch=='e'){
		if(dabi[chu]==0){
			
		}else if(dabi[chu]>=1 && dabi[chu]<=4){
			dabi[chu]*=2;
		}else if(dabi[chu]>=5 && dabi[chu]<=9){
			dabi[chu]*=1.5;
		}else if(dabi[chu]>=10 && dabi[chu]<=20){
			dabi[chu]+=2;
		}else{
			dabi[chu]++;
		}
		dabi[chu]=round(dabi[chu]);
	}else if(ch=='a'){
		if(ykmode){
	
		}else{
			dealtdamage[chu]=treetimes[chu]*treedam;
			if(cztmp[!chu]=='z'){
				if(dealtdamage[chu]<=csdef){
					leftmsg[chu]="随着一声'超闪'，你的攻击被防住了！"; 
				}else{
					leftmsg[chu]="随着一声'超闪'，你的攻击大多被防住了！";
					leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]-csdef).substr(0,3)+"点血量！";
					hp[!chu]-=dealtdamage[chu]-csdef;
				}
			}else if(cztmp[!chu]=='0'){
				leftmsg[chu]="随着一声'空'，你的攻击被防住了！";
			}else if(ifcszl[!chu] || cztmp[!chu]=='x'){//对面可能是红，后出 
				if(dealtdamage[chu]<=cszldef){
					leftmsg[chu]="随着一声'超闪之力'，你的攻击被防住了！"; 
				}else{
					leftmsg[chu]="随着一声'超闪之力'，你的攻击大多被防住了！"; 
					leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]-cszldef).substr(0,3)+"点血量！";
					hp[!chu]-=dealtdamage[chu]-cszldef;
				}
			}else if(cztmp[!chu]=='a' || cztmp[!chu]=='s'){
				if(cztmp[!chu]=='a'){
					dealtdamage[!chu]=treetimes[!chu]*treedam;
					if(dealtdamage[chu]==dealtdamage[!chu]){
						leftmsg[2]="两个锤互相抵消！";
					}else{
						leftmsg[2]="两个锤的伤害大多被互相抵消！";
					}
				}else{
					dealtdamage[!chu]=daotimes[!chu]*daodam;
					if(dealtdamage[chu]==dealtdamage[!chu]){
						leftmsg[2]="锤和刀互相抵消！";
					}else{
						leftmsg[2]="锤和刀的伤害大多被互相抵消！";
					}
				}
				if(dealtdamage[chu]==dealtdamage[!chu]){
				
				}else if(dealtdamage[chu]>dealtdamage[!chu]){
					leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]-dealtdamage[!chu]).substr(0,3)+"点血量！";
					hp[!chu]-=(dealtdamage[chu]-dealtdamage[!chu]);
				}else{
					/*
					leftmsg[chu]="扣你"+to_string(dealtdamage[!chu]-dealtdamage[chu]).substr(0,3)+"点血量！";
					hp[chu]-=(dealtdamage[!chu]-dealtdamage[chu]);
					*/
					/*
					如果蓝3tree 红1tree
					则caozuo(0)时蓝扣红5点
					caozuo(1)时红被蓝扣5点
					所以红共被扣10点
					申金bug 
					*/ 
				}
			}else{
				hp[!chu]-=dealtdamage[chu];
				leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]).substr(0,3)+"点血量！";
			}
			dabi[chu]-=treetimes[chu];
			zan[chu]-=treetimes[chu];
		}
	}else if(ch=='s'){
		if(ykmode){
	
		}else{
			dealtdamage[chu]=daotimes[chu]*daodam;
			if(cztmp[!chu]=='z'){
				if(dealtdamage[chu]<=csdef){
					leftmsg[chu]="随着一声'超闪'，你的攻击被防住了！";
				}else{
					leftmsg[chu]="随着一声'超闪'，你的攻击大多被防住了！";
					leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]-csdef).substr(0,3)+"点血量！";
					hp[!chu]-=dealtdamage[chu]-csdef;
				}
			}else if(cztmp[!chu]=='0'){
				leftmsg[chu]="随着一声'空'，你的攻击被防住了！";
			}else if(ifcszl[!chu] || cztmp[!chu]=='x'){
				if(dealtdamage[chu]<=cszldef){
					leftmsg[chu]="随着一声'超闪之力'，你的攻击被防住了！";
				}else{
					leftmsg[chu]="随着一声'超闪之力'，你的攻击大多被防住了！"; 
					leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]-cszldef).substr(0,3)+"点血量！";
					hp[!chu]-=dealtdamage[chu]-cszldef;
				}
			}else if(cztmp[!chu]=='s'){
				dealtdamage[!chu]=daotimes[!chu]*daodam;
				if(dealtdamage[chu]==dealtdamage[!chu]){
					leftmsg[2]="两个刀互相抵消！";
				}else{
					leftmsg[2]="两个刀的伤害大多被互相抵消！";
				}
				if(dealtdamage[chu]==dealtdamage[!chu]){
				
				}else if(dealtdamage[chu]>dealtdamage[!chu]){
					leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]-dealtdamage[!chu]).substr(0,3)+"点血量！";
					hp[!chu]-=dealtdamage[chu]-dealtdamage[!chu];
				}else{
					/*
					leftmsg[chu]="扣你"+to_string(dealtdamage[!chu]-dealtdamage[chu]).substr(0,3)+"点血量！";
					hp[chu]-=dealtdamage[!chu]-dealtdamage[chu]; 
					*/
				}
			}else{
				hp[!chu]-=dealtdamage[chu];
				leftmsg[!chu]="扣你"+to_string(dealtdamage[chu]).substr(0,3)+"点血量！";
			}
			dabi[chu]-=daotimes[chu];
		}
	}else if(ch=='z'){
		cstimes[chu]++;
		lstcs[chu]=rounds;
	}else if(ch=='x'){
        ifcszl[chu]=1; 
	}else if(ch=='0'){
		lstkong[chu]=rounds;
	}else if(ch=='/'){
		hp[chu]=-114514;//似辣！ 
	}else if(ch=='d'){
		ban[!chu][cztmp[!chu]]=1;//对方出啥禁啥
		 
	}else{
		cout<<"输出这个代表代码错误了。。。请找Literally114514修代码"<<endl;
	}
	if(ifcszl[chu]) ifcszl[chu]=0;//重置超闪之力 
	return;
}
void game(){
	mpmove['1']="攒";
	mpmove['2']="搭鼻";
	mpmove['3']="圆盾";
	mpmove['4']="方盾";
	mpmove['5']="上盾";
	mpmove['q']="兵粮寸断";
	mpmove['w']="水土不服";
	mpmove['e']="翻倍";
	mpmove['a']="锤";
	mpmove['s']="刀";
	mpmove['z']="超闪";
	mpmove['x']="超闪之力";
	mpmove['0']="空";
	mpmove['/']="哥我错了";
	mpmove['d']="蜜汁叉烧饭";
	 
	leftmsg[0]="";
	leftmsg[1]="";
	leftmsg[2]="";
	
	cout<<"我们两个一起！"<<endl;
	Sleep(350);
	cout<<"重！"<<endl;
	Sleep(250);
	cout<<"开！"<<endl;
	Sleep(250);
	cout<<"新！"<<endl;
	Sleep(250);
	cout<<"始！"<<endl;
	Sleep(250);
	
	caozuoing=1;
	upd();
	cout<<endl<<"蓝方，请你作出操作."<<endl;
	while(1){
		do{
			cztmp[0] = read();
			//cout<<cztmp[0];
			if(!ifhefa(cztmp[0],0)) cout<<"操作不合法！"<<endl; 
		}while(!ifhefa(cztmp[0],0));
		
		if(cztmp[0]=='a'){
			cout<<endl<<"请输入锤的次数(1-4)：";
			cin>>treetimes[0];
			while(!ifhefatimes(treetimes[0])){
				cout<<"操作不合法！"<<endl;
				Sleep(200);
				upd();
				cout<<endl<<"请输入锤的次数(1-4)：";
				cin>>treetimes[0];
			}
			while(dabi[chu]<treetimes[0] || zan[chu]<treetimes[0]){
				cout<<"资源不够！请重试！";
				Sleep(200);
				upd();
				cout<<endl<<"请输入锤的次数(1-4)：";
				cin>>treetimes[0];
			}
		}
		if(cztmp[0]=='s'){
			cout<<endl<<"请输入刀的次数(1-4)：";
			cin>>daotimes[0];
			while(!ifhefatimes(daotimes[0])){
				cout<<"操作不合法！"<<endl;
				Sleep(200);
				upd();
				cout<<endl<<"请输入刀的次数(1-4)：";
				cin>>daotimes[0];
			}
			while(dabi[chu]<daotimes[0]){
				cout<<"搭鼻不够！请重试！";
				Sleep(200);
				upd();
				cout<<endl<<"请输入刀的次数(1-4)：";
				cin>>daotimes[0];
			}
		}
		
		chu=!chu;//为了更新谁不能操作的提示 
		upd();
		
		cout<<endl<<"红方，请你作出操作."<<endl;
		do{
			cztmp[1] = read();
			if(!ifhefa(cztmp[1],1)) cout<<"操作不合法！"<<endl; 
		}while(!ifhefa(cztmp[1],1));
		
		if(cztmp[1]=='a'){
			cout<<endl<<"请输入锤的次数(1-4)：";
			cin>>treetimes[1];
			while(!ifhefatimes(treetimes[1])){
				cout<<"次数不合法！"<<endl;
				Sleep(200);
				upd();
				cout<<endl<<"请输入锤的次数(1-4)：";
				cin>>treetimes[1];
			}
			while(dabi[chu]<treetimes[1] || zan[chu]<treetimes[1]){
				cout<<"资源不够！请重试！";
				Sleep(200);
				upd();
				cout<<endl<<"请输入锤的次数(1-4)：";
				cin>>treetimes[1];
			}
		}
		
		if(cztmp[1]=='s'){
			cout<<endl<<"请输入刀的次数(1-4)：";
			cin>>daotimes[1];
			while(!ifhefatimes(daotimes[1])){
				cout<<"操作不合法！"<<endl;
				Sleep(200);
				upd();
				cout<<endl<<"请输入刀的次数(1-4)：";
				cin>>daotimes[1];
			}
			while(dabi[chu]<daotimes[1]){
				cout<<"搭鼻不够！请重试！";
				Sleep(200);
				upd();
				cout<<endl<<"请输入刀的次数(1-4)：";
				cin>>daotimes[1];
			}
		}
		
		chu=!chu;//为了更新谁不能操作的提示
		caozuoing=0; 
		upd();
		
	    caozuo(cztmp[0],0,0);
	    caozuo(cztmp[1],0,1);
	    upd();
	    updmove(cztmp[0],cztmp[1]);
	    rounds++;
	    if(leftmsg[0]!=""){
	    	cout<<"蓝方，"<<leftmsg[0]<<endl;//对蓝方说的话
	    	Sleep(1300);
		}
		if(leftmsg[1]!=""){
	    	cout<<"红方，"<<leftmsg[1]<<endl;//对红方说的话 
	    	Sleep(1300);
		}
		if(leftmsg[2]!=""){
	    	cout<<"系统："<<leftmsg[2]<<endl;//系统说的话 
	    	Sleep(1300);
		}
	    
	    caozuoing=1;
	    upd();
	    if(hp[0]<=0){
	    	qp();
	    	system("color C0");
	    	cout<<"游 戏 结 束！"<<endl;
	    	cout<<"红方胜利！"<<endl;
	    	cout<<"轮数："<<rounds<<endl;
	    	return;
		}
		if(hp[1]<=0){
	    	qp();
	    	system("color 3F");
	    	cout<<"游 戏 结 束！"<<endl;
	    	cout<<"蓝方胜利！"<<endl;
	    	cout<<"轮数："<<rounds<<endl;
	    	return;
		}
	    leftmsg[0]="";
	    leftmsg[1]="";
	    leftmsg[2]="";
		cout<<endl<<"蓝方，请你作出操作."<<endl;
	}
}
void startmenu(){
	//system("color 37");
	/*
	todo:
	输完操作后Beep一下 
	*/
	//求别反编译我 
	cout<<"-------------------"<<endl;
	cout<<"|   搭鼻,启动！   |"<<endl;
	cout<<"| 请选择游戏模式: |"<<endl;
	cout<<"|  1.PVP对战模式  |"<<endl;
	cout<<"|     ver:1.0     |"<<endl;
	cout<<"-------------------"<<endl;

	tips.push_back("搭鼻是作者写的最长，逻辑最恶心的小游戏，没有之一。");
	tips.push_back("因为作者精力有限，所以可选择的出招不多，QAQ");
	tips.push_back("你猜写C++搭鼻和写猪国杀哪个难？");
	tips.push_back("（啪）（啪）兵粮寸断！"); 
	tips.push_back("（啪）（啪）水土不服！");
	tips.push_back("（啪）（啪）ber→ber↗！");
	tips.push_back("因为“翻倍”过于逆天，已经进行削弱。");
	tips.push_back("有代码问题请私信Literally114514哦！");
	srand(time(0)); 
	cout<<"tips:"<<tips[rand()%tips.size()]<<endl<<endl;
	
	while(1){
		if (_kbhit()){
            cz = _getch();
            if(cz=='1'){
            	qp();
            	game();
            	return;
			}else if(cz=='\\'){
				cout<<"。。。？"<<endl;
				cout<<"你触发了彩蛋？"<<endl;
			}
        }
	}
	
}
int main(){
	startmenu();
	return 0;
}