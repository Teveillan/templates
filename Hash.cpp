// BKDR Hash Function
unsigned int BKDRHash(char*str) {
    unsigned int seed=131 ;// 31 131 1313 13131 131313 etc..
    unsigned int hash=0 ;
    for(int i=0; *str; ++i) {
        hash=hash*seed+(*str++);
    }
    return(hash % MOD);
}

// AP Hash Function
unsigned int APHash(char*str) {
    unsigned int hash=0 ;
    for(int i=0;*str;i++) {
        if((i&1)==0)
            hash^=((hash<<7)^(*str++)^(hash>>3));
        else
            hash^=(~((hash<<11)^(*str++)^(hash>>5)));
    }
    return(hash % MOD);
}

unsigned int DJBHash(char*str) {
    unsigned int hash=5381 ;
	for(int i=0; *str; ++i) {
        hash+=(hash<<5)+(*str++);
    }
    return(hash % MOD);
}
