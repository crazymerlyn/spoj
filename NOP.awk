BEGIN{FS="[A-Z]"}{s=0;for(i=2;i<NF;++i){s+=3-length($i)%4;}print s}
