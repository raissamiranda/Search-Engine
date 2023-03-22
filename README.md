# URL Scheduler

The main component of a search engine is a collector. With the large number os existing URLs actually, it's necessary to use a scheduler to define the collection order of the pages. An URL follows the format:
> -protocol-://-host--path-?-query-#-fragment-
  
The collector developed in this project, with no use of STL or other libraries, uses the depth-first strategy, which priorizes sites and URLs found first. The depth criterion priorizes URLs closer to the root of the site, that is:
> http:://ufmg.br 

must be collected before 
> http:://ufmg.br/dcc

## Usage
The collector will comunicate with its scheduler through an input file (given as argument, on the command line), which has a sequence of commands to be executed. A file will be created with the same name as the input file, but with the suffix -out in the same directory with the output data. The commands are:
```
● ADD_URLS <number>: adds the URLs informed in the following lines to the scheduler. The <quantity> parameter indicates how many lines will be read before the next command.
● ESCALONA_TUDO: scales all URLs following previously established rules. When scaled, URLs are displayed and removed from the list. 
● ESCALONA <number>: Limits the number of scaled URLs.
● ESCALONA_HOST <host> <number>: only URLs from this host are scaled.
● VER_HOST <host>: displays all host URLs, in order of priority.
● LISTA_HOSTS: displays all hosts, following the order in which they were known.
● LIMPA_HOST <host>: cleans the list of host URLs. 
● LIMPA_TUDO: cleans all URLs, including hosts.
```
 
## Example
### Input
```
ADD_URLS 5
http://www.globoesporte.com/page1.js?q=copa#group1
ftp://ftp.globo.com
http://www.globo.com/
http://www.uol.com.br/
http://www.superdownloads.com.br/
ESCALONA 2
LISTA_HOSTS
ADD_URLS 4
http://www.globo.com/videos/jornalnacional
http://globo.com/
http://globoesporte.com/spfc/index.html
http://globo.com/videos/
ESCALONA_HOST globo.com 2 
VER_HOST globo.com
```
  
### Output
```
http://globoesporte.com/page1.js?q=copa
http://globo.com
globoesporte.com
globo.com
uol.com.br
superdownloads.com.br  
http://globo.com
http://globo.com/videos
http://globo.com/videos/jornalnacional
```

## Execution's instructions
To install the program, it is necessary to acess the diretory where the program is stored
```
cd -directory-
```

Now, you must execute the make command and run the program with the name of the test .txt file:
```
makecd bin
./ main -pathtotest-
```



