#include <deque>
#include <Directory.h>
#include <Entry.h>
#include <FindDirectory.h>
#include <Path.h>
#include <stdio.h>

using std::deque;

int main(void)
{
	// Look up the home folder
	BPath path;
	find_directory(B_USER_DIRECTORY, &path);
	BDirectory dir(path.Path());
	
	deque<entry_ref> refDeque;
	
	entry_ref ref;
	while (dir.GetNextRef(&ref) == B_OK)
		refDeque.push_back(ref);
		
	printf("Contents of the home folder: %s\n", path.Path());
	for (deque<entry_ref>::iterator i = refDeque.begin(); i !=refDeque.end(); i++)
	{
		printf("\t%s\n", i->name);
	}
	
}
