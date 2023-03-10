# URL Scheduler

The main component of a search engine is a collector. With the large number os existing URLs actually, it's necessary to use a scheduler to define the collection order of the pages. An URL follows the format:
> -protocol-://-host--path-?-query-#-fragment-
  
The collector developed in this project, with no use of STL or other libraries, uses the depth-first strategy, which priorizes sites and URLs found first. The depth criterion priorizes URLs closer to the root of the site, that is:
> http:://ufmg.br 

must be collected before 
> http:://ufmg.br/dcc

## Example
The collector will comunicate with its scheduler through an input file (given as argument, on the command line), which has a sequence of commands to be executed. A file will be created with the same name as the input file, but with the suffix -out in the same directory with the output data. The commands are:

● ADD_URLS <number>: adds the URLs informed in the following lines to the scheduler.
  
The <quantity> parameter indicates how many lines will be read before the next command.
  
● SCALONA_TUDO: scales all URLs following previously established rules.
  
When scaled, URLs are displayed and removed from the list.
  
● SCALE <number>: Limits the number of scaled URLs.
  
● SCALE_HOST <host> <number>: only URLs from this host are scaled.
  
● VER_HOST <host>: displays all host URLs, in order of priority.
  
● LISTA_HOSTS: displays all hosts, following the order in which they were known.
  
● CLEAN_HOST <host>: cleans the list of host URLs.
  
● CLEAN_TUDO: cleans all URLs, including hosts.






## Execution's instructions
To install the program, it is necessary to acess the diretory where the program is stored
> cd -directory-

Now, you must execute the make command and run the program with the name of the test .txt file:
> make
 
> cd bin
 
> ./ main -pathtotest-



