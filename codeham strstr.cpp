class Solution{
	public:
		int Strstr(string haystack,string needle){
			const char *h=haystack.c_str();
			const char *n=needle.c_str();
			while(*h!= "\0"){
				const char *h1=h;
				const char *h2=n;
				while(*h1==*h2 && *h2!="\0"){
					h1++;h2++;
				}
				if(*h1=="\0"){
					return h-haystack.c_str();
				}
				h++;
			}
			return -1;
		}
};
