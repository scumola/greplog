#!/usr/bin/perl

# URL that generated this code:
# http://txt2re.com/index-perl.php3?s=62.175.249.249%20-%20-%20[27/Jun/2009:21:18:22%20-0400]%20%22GET%20/forum/index.php%20HTTP/1.1%22%20200%2016394%20%22http://compelature.com/forum/index.php%22%20%22Mozilla/4.0%20(compatible;%20MSIE%206.0;%20Windows%20NT%205.0;%20Avant%20Browser%20[avantbrowser.com];%20Hotbar%204.4.5.0)%22&1&14&6&4

while (<STDIN>) {
	$txt = $_;
	chop($txt);
#	$txt='62.175.249.249 - - [27/Jun/2009:21:18:22 -0400] "GET /forum/index.php HTTP/1.1" 200 16394 "http://compelature.com/forum/index.php" "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0; Avant Browser [avantbrowser.com]; Hotbar 4.4.5.0)"';

	$re1='((?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?))(?![\\d])';	# IPv4 IP Address 1
	$re2='.*?';	# Non-greedy match on filler
	$re3='(\\[.*?\\])';	# Square Braces 1
	$re4='.*?';	# Non-greedy match on filler
	$re5='(".*?")';	# Double Quote String 1
	$re6='.*?';	# Non-greedy match on filler
	$re7='(".*?")';	# Double Quote String 2
	$re8='.*?';	# Non-greedy match on filler
	$re9='(".*?")';	# Double Quote String 3

	$re=$re1.$re2.$re3.$re4.$re5.$re6.$re7.$re8.$re9;
	if ($txt =~ m/$re/is)
	{
		$ipaddress1=$1;
		$sbraces1=$2;
		$string1=$3;
		$string2=$4;
		$string3=$5;
		print ("--------------------------------------------------------------------------------------------------------\n");
		print ("IP: $ipaddress1\n");
		print ("DT: $sbraces1\n");
		print ("PA: $string1\n");
		print ("RF: $string2\n");
		print ("UA: $string3\n");
	}


}
