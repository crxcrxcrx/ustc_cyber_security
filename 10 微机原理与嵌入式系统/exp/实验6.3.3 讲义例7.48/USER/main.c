extern void strcopy(char *d,char *s);
int main ()  
{
	char *srcstr="0123456";
	char dststr[]="abcdefg";
	strcopy(dststr,srcstr);
	return 0;
}
