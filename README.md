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

Bugs
----

* Does not detect/handle duplicate page names (so you can not just cat multiple pagecounts files together as input to this program)

