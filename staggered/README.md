# Deconvolute_staggered

## Compiling and Boost libraries
This program requires the C++ Boost libraries to be installed on the server.  
Compiling with g++ (all on one line)

> g++ Deconvolute_staggered.cpp Engine.cpp DataStore.cpp -I \<path to boost installation\> -L \<path to boost libraries\> -lboost_iostreams -o Deconvolute_staggered.exe 2> errors.txt

Any errors in the compiling will be saved to the errors.txt file. If this file has zero size the build as worked. If not look in the file and resolve the first error and then rebuild until it works.

## Command line arguments

> Deconvolute_staggered.exe Read1.fastq.gz Read2.fastq.gz primers.txt indexes.txt results_Folder 190 350

Parameters on command line: 
|Parameter|Example|Comment|
|-|-|-|
|Read one filename  |read1.fastq.gz|File name and path|  
|Read two filename |read2.fastq.gz|File name and path| 
|Primer file  |primers.txt|File name and path|
|Index file  |indexes.txt|File name and path|
|Folder to save data in |results_Folder|Path to export folder: this most exist before start of analysis|
|Minimum PCR length |190|Any value above 50 and less than the expected amplicon size (Do not be overly stringent with this value)| 
|Maximum PCR length |350|Any value above 50 and greater than the expected amplicon size (Do not be overly stringent with this value)|   

### Example primer file
GGATTGCGCTGTTATCC  
AGACGAGAAGACCCTAT  

These sequences can contain degenerate bases: S, W, R or Y.

### Example index file
AACTGTAG  
ACACTAAG  
ACAGGCGC  
ACTCGTGT  
AGTACTCC  
ATTGTGAA  
CAATTAAC  
CATAGAGT  
CCATTCGA  
CCTTCACC  
GACGTCTT   
GCCACAGG  
GTCTACAC  
GTGAATAT  
GTGTCGGA  
TAAGGTCA  
TGCGAGAC  
TGGCCGGT  
TTCCTGTT  
TTGCCTAG  

These sequences can only contain standard bases: A, C, G or T.

## Example of reads with Primers

|Sequence|Comment|
|-|-|
|1)||
|``ATGGGGACTCGTGTGGATTGCGCTGTTATCCCTAGGGTA``| Start of read with forward primer and 6 N's|
|``--------------GGATTGCGCTGTTATCC``|Target primer sequence which is 14 to 17 bp from start|
|``------ACTCGTGT``|Index sequence which is before the target sequence|
|``NNNNNN``|Unique id and stagger to create difference offset to aid base calling|
|2)||
|``ATTCGTACACTAAGAGACGAGAAGACCCTATGGAGCTTT``|Start of read with reverse primer and 6 N's|
|``--------------AGACGAGAAGACCCTAT``||
|``------ACACTAAG``||
|``NNNNNN``||
|3)||
|``TTCAGTCCAATTAACGGATTGCGCTGTTATCCCTAGGGT``|Start of read with forward primer and 7 Ns|
|``---------------GGATTGCGCTGTTATCC``||
|``-------CAATTAAC``||
|``NNNNNNN``||
