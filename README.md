Show Wikipedia Top Pages
========================

This is simple C program to show most accessed pages on Wikipedia from large
dataset.

Setup
-----

Compile program:

	make

Get sample dataset from: http://dumps.wikimedia.org/other/pagecounts-raw/2014/2014-08/

Run program in pipe, for example:

	zcat pagecounts-20140820-160000.gz | toppages


