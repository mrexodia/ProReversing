ProReversing Framework
============

This project gathers anti-anti-reversing techniques into an open library. The resulting DLL can be easily incorporated into all reverse engineering tools. It works under 

* Windows XP 32 bits
* Windows Vista 32 bits
* Windows 7 32 bits
* Windows Vista 64 bits
* Windows 7 64 bits

For more information, see [my blog](http://malwaremuncher.blogspot.com/2012/11/towards-anti-anti-reversing-framework.html).


### TODO
- [ ] BeingDebugged 


Build Prerequisites
--------------

* If you want to execute the injection test, you will have to download the Dll-Injector project. If not, comment it out.

ProReversing explained:
--------------
There are couple of things in order to make ProReversing good.
It MUST NOT crash, because this will lead to process crashing. Since we may have bugs ProReversing's code
is placed between SEH statements.
Second, changing inner OS structures in order to fool anti debugged process is dangerous. Threads could change those inner OS structures   
and can cause a real trouble ( and we should stay away from LOCKS, it's a recipe of a disaster - this is optional to the user, since 
good anti debugging code wont trust WinAPI ). As a result
ProReversing code, hooks common Windows API functions that are used for anti debugging. 