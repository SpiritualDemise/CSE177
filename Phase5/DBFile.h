#ifndef DBFILE_H
#define DBFILE_H

#include <string>

#include "Config.h"
#include "Record.h"
#include "Schema.h"
#include "File.h"

using namespace std;


class DBFile {
private:
	File file;
	string fileName;
	FileType fileType;
	//currPage turned to Page for simplicity
	Page page;
	//filecount turned to currpage for simplicity
	off_t currPage = 0;

public:
	DBFile ();
	virtual ~DBFile ();
	DBFile(const DBFile& _copyMe);
	DBFile& operator=(const DBFile& _copyMe);

	int Create (char* fpath, FileType file_type);
	int Open (char* fpath);
	int Close ();

	void Load (Schema& _schema, char* textFile);
	void WriteToPage();

	void MoveFirst ();
	void AppendRecord (Record& _addMe);
	int GetNext (Record& rec);
};

#endif //DBFILE_H
