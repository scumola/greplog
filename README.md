greplog
=======

When grep can't cut it and you don't want to buy splunk, use greplog!

This tool parses standard apache/nginx web logs and parses out the big fields that you can run stuff on.  The C one works better than the perl one if you're parsing big logs.  Both the C one and the perl one do the same thing.


usage
=====
greplog < /var/log/apache2/access.log


output
======
```
[root@blah ~]# greplog < /var/log/nginx/access.log | head -n 30                                         
--------------------------------------------------
IP: 10.214.11.99
TD: [26/Mar/2013:08:03:03 +0000]
PA: "200"
RC: 574
SZ: 347613
RF: " "
UA: " "
--------------------------------------------------
IP: 10.214.11.99
TD: [26/Mar/2013:08:03:03 +0000]
PA: "401"
RC: 2
SZ: 0
RF: "-"
UA: "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.1) Gecko/2008070208 Firefox/3.0.1"
--------------------------------------------------
IP: 10.214.11.99
TD: [26/Mar/2013:08:03:03 +0000]
PA: "200"
RC: 53
SZ: 5
RF: "http://www.dishanywhere.com/"
UA: "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_2) AppleWebKit/536.26.17 (KHTML, like Gecko) Version/6.0.2 Safari/536.26.17"
--------------------------------------------------
IP: 10.214.11.99
TD: [26/Mar/2013:08:03:03 +0000]
PA: "200"
RC: 76
SZ: 6
```

then things like this are possible
==================================
(find the top-10 most common useragents)

```
[root@ip-10-251-9-164 ~]# greplog < /var/log/apache2/access.log | grep "UA:" | sort | uniq -c | sort -rn | head -n 10
  15986 UA: " "
  15037 UA: "Mozilla/5.0 (compatible; Googlebot/2.1; +http://www.google.com/bot.html)"
   1813 UA: "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:19.0) Gecko/20100101 Firefox/19.0"
   1593 UA: "Mozilla/5.0 (compatible; bingbot/2.0; +http://www.bing.com/bingbot.htm)"
   1487 UA: "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.22 (KHTML, like Gecko) Chrome/25.0.1364.172 Safari/537.22"
   1482 UA: "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0)"
    847 UA: "msnbot-UDiscovery/2.0b (+http://search.msn.com/msnbot.htm)"
    468 UA: "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/5.0)"
    465 UA: "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.22 (KHTML, like Gecko) Chrome/25.0.1364.172 Safari/537.22"
    437 UA: "Mozilla/5.0 (Windows NT 5.1; rv:19.0) Gecko/20100101 Firefox/19.0"
```


build
=====
gcc greplog.c -o greplog -lpcre
