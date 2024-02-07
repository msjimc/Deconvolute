# Deconvolute

## Compiling and Boost libraries
This program requires the C++ Boost libraries to be installed on the server.  
Compiling with g++ (all on one line)

> g++ Deconvoluted_plain.cpp Engine.cpp DataStore.cpp -I \<path to boost installation\> -L \<path to boost libraries\> -lboost_iostreams -o Deconvolute.exe 2> errors.txt

Any errors in the compiling will be saved to the errors.txt file. If this file has zero size the build as worked. If not look in the file and resolve the first error and then rebuild until it works.

## Command line arguments

Read one filename with path,  
Read two filename with path,  
Primer file with path,  
Index file with path,  
Path to folder to save data in,  
Minimum PCR length,  
Maximum PCR length.  
 

### Example primer file
CGTGCCAGCCACCGCG  
GGGTATCTAATCCYAGTTTG   

These sequences can contain degenerate bases: S, W, R or Y.
#### Make sure the files have Unix line ends for use on Linux

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
#### Make sure the files have Unix line ends for use on Linux

## Library production

The Sequence is PCR amplified with the primers of interest and the product cleaned up to remove primer dimer and primers. The amplicon is then used to make a whole genome library with a kit like the NEB NextUltra.   

## Example of reads with Primers

|Sequence|Comment|
|-|-|
|1)|Forward sequence|
|``GGGACTCGTGTGGATTGCGCTGTTATCCCTAGGGTA``| Start of read with forward primer|
|``-----------GGATTGCGCTGTTATCC``|Target primer sequence which is 14 to 17 bp from start|
|``----ACTCGTGT``|Index sequence which is before the target sequence|
|``NNNN``|Unique id and stagger to create difference offset to aid base calling|
|2)|Reverse complement|
|``ATTCGTACACTAAGAGACGAGAAGACCCTATGGAGCTTT``|Start of read with reverse prime|
|``------------AGACGAGAAGACCCTAT``||
|``----ACACTAAG``||
|``NNNNNN``||

