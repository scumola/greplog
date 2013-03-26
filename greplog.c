#include <stdio.h>
#include <string.h>
#include <pcre.h>

int main(int argc, char **argv)
{
	const char *error;
	int erroffset;
	int ovector[186];
	char re[8192]="";
	char txt[8192]="";
	int ret;

	//  char txt[]="62.175.249.249 - - [27/Jun/2009:21:18:22 -0400] \"GET /forum/index.php HTTP/1.1\" 200 16394 \"http://compelature.com/forum/index.php\" \"Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0; Avant Browser [avantbrowser.com]; Hotbar 4.4.5.0)\"";

	char re1[]="((?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?))(?![\\d])";	// IPv4 IP Address 1
	strcat(re,re1);
	char re2[]=".*?";	// Non-greedy match on filler
	strcat(re,re2);
	char re3[]="(\\[.*?\\])";	// Square Braces 1
	strcat(re,re3);
	char re4[]=".*?";	// Non-greedy match on filler
	strcat(re,re4);
	char re5[]="(\".*?\")";	// Double Quote String 1
	strcat(re,re5);
	char re6[]=".*?";	// Non-greedy match on filler
	strcat(re,re6);
	char re7[]="(\\d+)";	// Integer Number 1
	strcat(re,re7);
	char re8[]=".*?";	// Non-greedy match on filler
	strcat(re,re8);
	char re9[]="(\\d+)";	// Integer Number 2
	strcat(re,re9);
	char re10[]=".*?";	// Non-greedy match on filler
	strcat(re,re10);
	char re11[]="(\".*?\")";	// Double Quote String 2
	strcat(re,re11);
	char re12[]=".*?";	// Non-greedy match on filler
	strcat(re,re12);
	char re13[]="(\".*?\")";	// Double Quote String 3
	strcat(re,re13);


	pcre *r =  pcre_compile(re, PCRE_CASELESS|PCRE_DOTALL, &error, &erroffset, NULL);

	while ( fgets(txt,8192,stdin) ) {
//		printf("%s\n",txt);
		int rc = pcre_exec(r, NULL, txt, strlen(txt), 0, 0, ovector, 186);

		if (rc>0)
		{
			printf("--------------------------------------------------\n");
			char ipaddress1[1024];
			pcre_copy_substring(txt, ovector, rc,1,ipaddress1, 1024);
			printf("IP: %s\n",ipaddress1);
			char sbraces1[1024];
			pcre_copy_substring(txt, ovector, rc,2,sbraces1, 1024);
			printf("TD: %s\n",sbraces1);
			char string1[1024];
			pcre_copy_substring(txt, ovector, rc,3,string1, 1024);
			printf("PA: %s\n",string1);
			char int1[1024];
			pcre_copy_substring(txt, ovector, rc,4,int1, 1024);
			printf("RC: %s\n",int1);
			char int2[1024];
			pcre_copy_substring(txt, ovector, rc,5,int2, 1024);
			printf("SZ: %s\n",int2);
			char string2[1024];
			pcre_copy_substring(txt, ovector, rc,6,string2, 1024);
			printf("RF: %s\n",string2);
			char string3[1024];
			pcre_copy_substring(txt, ovector, rc,7,string3, 1024);
			printf("UA: %s\n",string3);

		}
	}
}

