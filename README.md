Show Wikipedia Top Pages
========================

This is simple C program to show most accessed pages on Wikipedia from large
dataset. No rocket science here, just prototype.

Setup
-----

Compile program:

	make

Get sample dataset from: http://dumps.wikimedia.org/other/pagecounts-raw/2014/2014-08/

Run program in pipe, for example:

	zcat pagecounts-20140820-160000.gz | toppages
	TOP LIST
	========
	01.                                          Main_Page          800836
	02.                     Special:CentralAutoLogin/start          174535
	03.                                     Special:Search          105209
	04.                                     Special:Random           92901
	05.                               Ice_Bucket_Challenge           31122
	06.                                         Maattrraan           21791
	07.                                         Amazon.com           19859
	08.                      Amyotrophic_lateral_sclerosis           17089
	09.                     Direct-to-consumer_advertising           10028
	10.               Islamic_State_of_Iraq_and_the_Levant            7666

Hmm...


Bugs
----

* Does not detect/handle duplicate page names (so you can not just cat multiple pagecounts files together as input to this program)
* Shows counts for 'en' pages only (this is to avoid duplicates in input)
