#include <bits/stdc++.h>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;


const double treedam=2.5;
const double daodam=1;
const double csdef=7;
const double cszldef=3.5;
const double hui_per_yd=1.5;

double zan[2],dabi[2],fdun[2],ydun[2];
double hp[2]={1.5,1.5},damage[2],defense[2],addi_damage[2];
double treetimes[2],daotimes[2];
map <char,bool> ban[2];//蜜汁叉烧饭 
char cz,cztmp[2];
string yingkongcin,dealtdamagemsg;
bool ifcszl[2],cszlflag[2];
int lstcs[2]={-2,-2},lstkong[2]={-100,-100};
int rounds=0,cstimes[2];
bool chu=0,caozuoing;//0蓝方，1红方
bool easteregg;
string leftmsg[3];
map <char,string> mpmove;
char treeindex[105]={' ','a','A','S','D'};
char daoindex[105]={' ','s','Z','X','C'};
vector<string> tips;

int how_digit(double a){
	string tmp=to_string(a);
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
	if(c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='6' && c!='q' && c!='w' && c!='e' && c!='a' && c!='s' && c!='d' && c!='z' && c!='x' && c!='0' && c!='/' && c!='p'){
		return 0;
	}
	if(c=='a' && zan[b]<1 && dabi[b]<1) return 0;
	if(c=='s' && dabi[b]<1) return 0;
	if(c=='q' && fdun[b]<1) return 0;
	if(c=='w' && fdun[b]<2) return 0;
	if(c=='e' && fdun[b]<3) return 0;
	if(cztmp[b]=='z' && rounds-lstcs[b]<=1) return 0;
	if(cztmp[b]=='x' && cstimes[b]<2) return 0;
	if(cztmp[b]=='0' && rounds-lstkong[b]<=10) return 0;
	if(ban[b][c]==1) return 0;
	return 1;
}
bool ifhefatimes(int c,bool chu,int type){
	if(type==0){
		if(1<=c && c<=4 && zan[chu]>=c && dabi[chu]>=c){
			return 1;
		}
	}else{
		if(1<=c && c<=4 && dabi[chu]>=c){
			return 1;
		}
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
	}else if(a==7){
		return "七";
	}else{
		
	}
	return "代码出Bug了？";
}
void upd(){
	qp();
	int lantotlength1=25+how_digit(zan[0])+how_digit(dabi[0])+how_digit(ydun[0])+how_digit(fdun[0]);
	int hongtotlength1=26+how_digit(zan[1])+how_digit(dabi[1])+how_digit(ydun[1])+how_digit(fdun[1]);
	int lantotlength2=4;
	int hongtotlength2=4;
	string lanbannedlist="禁：";
	string hongbannedlist="禁：";
	
	int hplength1=6+how_digit(hp[0]);
	int hplength2=6+how_digit(hp[1]);
	
	for(auto it=ban[0].begin();it!=ban[0].end();it++){//ban[0]：蓝被ban
		if((it->second)==1){
			if(mpmove[it->first]=="超闪之力"){//超闪之力与超闪重名了
				lanbannedlist+="力";
				lanbannedlist+=" ";
				lantotlength2+=3;
			}else if(it->first=='A' || it->first=='S' || it->first=='D'){//2-4锤都算锤，不重复禁
				
			}else if(it->first=='Z' || it->first=='X' || it->first=='C'){//刀同理
				
			}else{
				lanbannedlist+=mpmove[it->first].substr(0,2);
				lanbannedlist+=" ";
				lantotlength2+=3;
			}
		}
	}
	for(auto it=ban[1].begin();it!=ban[1].end();it++){
		if((it->second)==1){
			if(mpmove[it->first]=="超闪之力"){
				hongbannedlist+="力";
				hongbannedlist+=" ";
				hongtotlength2+=3;
			}else if(it->first=='A' || it->first=='S' || it->first=='D'){
				
			}else if(it->first=='Z' || it->first=='X' || it->first=='C'){
				
			}else{
				hongbannedlist+=mpmove[it->first].substr(0,2);
				hongbannedlist+=" ";
				hongtotlength2+=3;
			}
		}
	}
	//cout<<ifcszl[0]<<' '<<ifcszl[1]<<endl;
	cout<<"-------------------蓝方--------------------------------------红方-------------------"<<endl;
	
	cout<<"|攒："<<zan[0]<<" 搭鼻："<<dabi[0]<<" 圆盾："<<ydun[0]<<" 方盾："<<fdun[0];
	for(int i=1;i<=40-lantotlength1;i++) cout<<" ";
	cout<<"|";
	for(int i=1;i<=40-hongtotlength1;i++) cout<<" ";
	cout<<" 攒："<<zan[1]<<" 搭鼻："<<dabi[1]<<" 圆盾："<<ydun[1]<<" 方盾："<<fdun[1];
	cout<<"|"<<endl;
	
	cout<<"|血量："<<hp[0];
	for(int i=1;i<=40-hplength1;i++) cout<<" ";
	cout<<"|";
	for(int i=1;i<=40-hplength2;i++) cout<<" ";
	cout<<"血量："<<hp[1]<<"|"<<endl;
	
	cout<<"|"<<lanbannedlist;
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
	cout<<"1:攒 2:搭鼻 3:圆盾 4:方盾 5:上盾 6:翻倍"<<endl;
	cout<<"q:兵粮寸断！ w:水土不服！e:乐不思蜀！"<<endl;
	cout<<"a1-a4:锤-锤锤锤锤! s1-s4:刀-青龙偃月刀！d:蜜汁叉烧饭！"<<endl;
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
//------------------------------------------------------------------------------------------------------------
void ykcaozuo(char ch,bool chu){
	if(ch=='1'){
		zan[chu]++;
	}else if(ch=='2'){
		dabi[chu]++;
	}else if(ch=='3'){
		ydun[chu]++;
	}else if(ch=='5'){
		if(ydun[chu]==0){
			leftmsg[chu]="没有圆盾你上个毛！";
		}else{
			hp[chu]+=ydun[chu]*hui_per_yd;
			ydun[chu]=0;
		}
	}else if(ch=='6'){
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
	}else{
		
	}
	return;
}
void yingkong(int times,bool chu){
	cout<<a(!chu)<<"已经被硬控！请"<<a(chu)<<"输入"<<num_to_hanzi(times)<<"个字符，代表"<<num_to_hanzi(times)<<"次操作。"<<endl;
	cin>>yingkongcin;
	if(yingkongcin.length()>times) cout<<"次数超过"<<times<<"，自动截取前"<<num_to_hanzi(times)<<"个字符。"<<endl;
	for(int i=0;i<times;i++){
		ykcaozuo(yingkongcin[i],chu);
	}
	return;
}
void updstatus(){
	
}
void caozuo(char ch,bool chu){
	if(ch=='1'){
		zan[chu]++;
	}else if(ch=='2'){
		dabi[chu]++;
	}else if(ch=='3'){
		ydun[chu]++;
	}else if(ch=='4'){
		fdun[chu]++;
	}else if(ch=='5'){
		if(ydun[chu]==0){
			leftmsg[chu]="没有圆盾你上个毛！";
		}else{
			hp[chu]+=ydun[chu]*hui_per_yd;
			ydun[chu]=0;
		}
		
	}else if(ch=='6'){
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
	}else if(ch=='q'){
		fdun[chu]--;
		if(cztmp[!chu]=='0'){
			leftmsg[chu]="随着一声'空'，你的硬控被防住了！";
		}else if(cztmp[!chu]=='z'){
			leftmsg[chu]="随着一声'超闪'，你的硬控被防住了！";
		}else if(ifcszl[!chu] || cztmp[!chu]=='x'){
			leftmsg[chu]="随着一声'超闪之力'，你的硬控被防住了！";
		}else if(cztmp[!chu]=='q'){
			leftmsg[2]="两个硬控互相抵消！";
		}else if(cztmp[!chu]=='w'){
			yingkong(2,!chu);
		}else if(cztmp[!chu]=='e'){
			yingkong(4,!chu);
		}else{
			yingkong(3,chu);
		}
	}else if(ch=='w'){
		fdun[chu]-=2;
		if(cztmp[!chu]=='0'){
			leftmsg[chu]="随着一声'空'，你的硬控被防住了！";
		}else if(cztmp[!chu]=='z'){
			cout<<"随着一声'超闪'，你的硬控被防住了！"<<endl; 
		}else if(ifcszl[!chu] || cztmp[!chu]=='x'){
			cout<<"随着一声'超闪之力'，你的硬控被防住了！"<<endl;
		}else if(cztmp[!chu]=='q'){
			
		}else if(cztmp[!chu]=='w'){
			leftmsg[2]="两个硬控互相抵消！";
		}else if(cztmp[!chu]=='e'){
			yingkong(2,!chu);
		}else{
			yingkong(5,chu);
		}
	}else if(ch=='e'){
		fdun[chu]-=3;
		if(cztmp[!chu]=='0'){
			leftmsg[chu]="随着一声'空'，你的硬控被防住了！";
		}else if(cztmp[!chu]=='z'){
			yingkong(7,chu);
		}else if(ifcszl[!chu] || cztmp[!chu]=='x'){
			cout<<"随着一声'超闪之力'，你的硬控被防住了！"<<endl;
		}else if(cztmp[!chu]=='q'){
			
		}else if(cztmp[!chu]=='w'){
			
		}else if(cztmp[!chu]=='e'){
			leftmsg[2]="两个硬控互相抵消！";
		}else{
			yingkong(7,chu);
		}
	}else if(ch=='a' || ch=='A' || ch=='S' || ch=='D'){
		damage[chu]+=treetimes[chu]*treedam;
		if(cztmp[!chu]=='0'){
			leftmsg[chu]="随着一声'空'，你的攻击被防住了！";//“空”有特殊台词
		}
		dabi[chu]-=treetimes[chu];
		zan[chu]-=treetimes[chu];
		//leftmsg[2]=to_string(chu)+" "+to_string(damage[chu])+" "+to_string(damage[!chu]);
	}else if(ch=='s' || ch=='Z' || ch=='X' || ch=='C'){
		damage[chu]=daotimes[chu]*daodam;
		if(cztmp[!chu]=='0'){
			leftmsg[chu]="随着一声'空'，你的攻击被防住了！";
		}
		dabi[chu]-=daotimes[chu];
	}else if(ch=='z'){
		defense[chu]+=csdef;
		cstimes[chu]++;
		lstcs[chu]=rounds;
	}else if(ch=='x'){
		defense[chu]+=cszldef;
        ifcszl[chu]=1;
        cszlflag[chu]=1;
	}else if(ch=='0'){
		defense[chu]+=10000000;
		lstkong[chu]=rounds;
	}else if(ch=='/'){
		if(cztmp[!chu]=='/'){
			easteregg=1;
		}
		hp[chu]=-114514;//似辣！ 
	}else if(ch=='d'){
		if(cztmp[!chu]=='0'){
			leftmsg[chu]="随着一声'空'，你的攻击被防住了！";
		}else if(cztmp[!chu]=='a' || cztmp[!chu]=='A' || cztmp[!chu]=='S' || cztmp[!chu]=='D'){
			ban[!chu]['a']=1;
			ban[!chu]['A']=1;
			ban[!chu]['S']=1;
			ban[!chu]['D']=1;
		}else if(cztmp[!chu]=='s' || cztmp[!chu]=='Z' || cztmp[!chu]=='X' || cztmp[!chu]=='C'){
			ban[!chu]['s']=1;
			ban[!chu]['Z']=1;
			ban[!chu]['X']=1;
			ban[!chu]['C']=1;
		}else{
			ban[!chu][cztmp[!chu]]=1;//对方出啥禁啥
		}
		addi_damage[chu]+=3.5;//非代码错误，真实伤害！！！！ 
	}else if(ch=='p'){
		zan[0]=100;
		zan[1]=100;
		dabi[0]=100;
		dabi[1]=100;
		fdun[0]=100;
		fdun[1]=100;
		ydun[0]=100;
		ydun[1]=100;
		cstimes[0]=2;
		cstimes[1]=2;
		hp[0]=100;
		hp[1]=100;
	}else{
		cout<<"输出这个代表代码错误了。。。请找Literally114514修代码"<<endl;
	}
	return;
}
void game(){
	mpmove['1']="攒";
	mpmove['2']="搭鼻";
	mpmove['3']="圆盾";
	mpmove['4']="方盾";
	mpmove['5']="上盾";
	mpmove['6']="翻倍";
	mpmove['q']="兵粮寸断";
	mpmove['w']="水土不服";
	mpmove['e']="乐不思蜀";
	mpmove['a']="锤";
	mpmove['A']="锤锤";
	mpmove['S']="锤锤锤";
	mpmove['D']="锤锤锤锤";

	mpmove['s']="刀";
	mpmove['Z']="连刀";
	mpmove['X']="大砍刀";
	mpmove['C']="青龙偃月刀";
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
			if(!ifhefa(cztmp[0],0)) cout<<"操作不合法！"<<endl; 
		}while(!ifhefa(cztmp[0],0));
		
		if(cztmp[0]=='a'){
			do{
				treetimes[0] = read() - '0';
				if(!ifhefatimes(treetimes[0],0,0)) cout<<"次数不合法！"<<endl; 
			}while(!ifhefatimes(treetimes[0],0,0));
			cztmp[0]=treeindex[(int)treetimes[0]];
		}
		if(cztmp[0]=='s'){
			do{
				daotimes[0] = read() - '0';
				if(!ifhefatimes(daotimes[0],0,1)) cout<<"次数不合法！"<<endl; 
			}while(!ifhefatimes(daotimes[0],0,1));
			cztmp[0]=daoindex[(int)daotimes[0]];
		}
		
		chu=!chu;//为了更新谁不能操作的提示 
		upd();
		
		cout<<endl<<"红方，请你作出操作."<<endl;
		do{
			cztmp[1] = read();
			if(!ifhefa(cztmp[1],1)) cout<<"操作不合法！"<<endl; 
		}while(!ifhefa(cztmp[1],1));
		
		if(cztmp[1]=='a'){
			do{
				treetimes[1] = read() - '0';
				if(!ifhefatimes(treetimes[1],1,0)) cout<<"次数不合法！"<<endl; 
			}while(!ifhefatimes(treetimes[1],1,0));
			cztmp[1]=treeindex[(int)treetimes[1]];
		}
		if(cztmp[1]=='s'){
			do{
				daotimes[1] = read() - '0';
				if(!ifhefatimes(daotimes[1],1,1)) cout<<"次数不合法！"<<endl; 
			}while(!ifhefatimes(daotimes[1],1,1));
			cztmp[1]=daoindex[(int)daotimes[1]];
		}
		
		caozuoing=0; 
		chu=!chu;
		upd();
		
	    caozuo(cztmp[0],0);
	    caozuo(cztmp[1],1);
	    
	    /*
	    addi_damage:扣自己血量，不参与抵消（如蜜汁叉烧饭）
	    */
		if(damage[0]>damage[1]){//大马哥
			double damcha=damage[0]-damage[1];
			if(damcha>defense[1]){
				damcha-=defense[1];
				hp[1]-=damcha;
				leftmsg[1]="扣你"+to_string(damcha).substr(0,3)+"点血量！";
			}else{
				leftmsg[0]="你的攻击被防住了！";
			}
		}else if(damage[0]<damage[1]){
		    double damcha=damage[1]-damage[0];
			if(damcha>defense[0]){
				damcha-=defense[0];
				hp[0]-=damcha;
				leftmsg[0]="扣你"+to_string(damcha).substr(0,3)+"点血量！";
			}else{
				leftmsg[1]="你的攻击被防住了！";
			}
		}else{
			if(damage[0]!=0 && damage[1]!=0) leftmsg[2]="伤害被抵消！";
		}
	    if(addi_damage[0]>0){
			leftmsg[2]+="蓝方扣自己";
			leftmsg[2]+=to_string(addi_damage[0]).substr(0,3);
			leftmsg[2]+="点血量！";
			hp[0]-=addi_damage[0];
		}
		if(addi_damage[1]>0){
			leftmsg[2]+="红方扣自己";
			leftmsg[2]+=to_string(addi_damage[1]).substr(0,3);
			leftmsg[2]+="点血量！";
			hp[1]-=addi_damage[1];
		}
		damage[0]=0;
	    damage[1]=0;
	    defense[0]=0;
	    defense[1]=0;
	    addi_damage[0]=0;
	    addi_damage[1]=0;
	    
	    if(cszlflag[0]){
	    	cszlflag[0]=0;
		}else{
			if(ifcszl[0]){
				ifcszl[0]=0;
			}
		}
		if(cszlflag[1]){
	    	cszlflag[1]=0;
		}else{
			if(ifcszl[1]){
				ifcszl[1]=0;
			}
		}
		
		if(ifcszl[0]) defense[0]+=cszldef;
		if(ifcszl[1]) defense[1]+=cszldef;
	    if(easteregg){
	    	qp();
	    	system("color 56");
	    	cout<<"恭喜你，触发彩蛋！！！！！！！"<<endl;
	    	cout<<"因为两边同时认输，你获得了红蓝的结合体颜色！"<<endl;
	    	return;
		}
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
	    if(hp[0]<=0 && hp[1]<=0){
	    	qp();
	    	system("color 60");
	    	cout<<"游 戏 结 束！"<<endl;
	    	cout<<"平局了！"<<endl;
	    	cout<<"轮数："<<rounds<<endl;
	    	return;
		}
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
	1:资源类
	2:攻击类/硬控类
	3:防  
	4:特殊（密） 
	
	1-2/1-4/2-4/3-4：被打
	2-2：抵消
	2-3：两边都成功
	3-3；抵消
	硬控：只1 
	*/
	cout<<"-------------------"<<endl;
	cout<<"|   搭鼻,启动！   |"<<endl;
	cout<<"| 请选择游戏模式: |"<<endl;
	cout<<"|  1.PVP对战模式  |"<<endl;
	cout<<"|     ver:1.0     |"<<endl;
	cout<<"-------------------"<<endl;
	cout<<"临时更新：蜜汁叉烧饭扣自己3.5血"<<endl;

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