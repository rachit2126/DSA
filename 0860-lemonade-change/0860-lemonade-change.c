bool lemonadeChange(int* bills, int billsSize) {
    int five=0,  ten=0;
    for(int i=0;i<billsSize;i++){
        if(bills[i]==5) five++;
        else if(bills[i]==10){
            ten++;
            if(five) five--;
            else return false;
        }
        else {
            if(five && ten){
                ten--;
                five--;
            }else if(five>2){
                five-=3;
            }else return false;
        }
    }
    return true;
}