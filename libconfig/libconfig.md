# libconfig安装及配置文件简单示例

## 1.下载

官网下载 libconfig-1.7.2.tar.gz

## 2.安装

安装包：libconfig-1.7.2.tar.gz

```shell
安装过程：解压，配置，编译，安装
//解压安装包
tar -zxvf libconfig-1.7.2.tar.gz 
//安装前的引导配置，默认安装到/usr/local，可以通过./configure --prefix=PREFIX进行修改，也可以修改脚本参数ac_default_prefix的值
cd libconfig-1.7.2;
./configure 
//编译源码
make
//安装前的检查
make check
//安装
make install
```


复制库到/usr/lib

复制库到/usr/lib

```shell
cp /usr/local/lib/libconfig* /usr/lib
```

## 3.使用示例

### main.cc

```cpp
/* ----------------------------------------------------------------------------
   libconfig - A library for processing structured configuration files
   Copyright (C) 2005-2010  Mark A Lindner

   This file is part of libconfig.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not, see
   <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

// This example reads the configuration file 'example.cfg' and displays
// some of its contents.

int main(int argc, char **argv)
{
  Config cfg;

  // Read the file. If there is an error, report it and exit.
  try
  {
    cfg.readFile("example.cfg");
  }
  catch(const FileIOException &fioex)
  {
    std::cerr << "I/O error while reading file." << std::endl;
    return(EXIT_FAILURE);
  }
  catch(const ParseException &pex)
  {
    std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << std::endl;
    return(EXIT_FAILURE);
  }

  // Get the store name.
  try
  {
    string name = cfg.lookup("name");
    cout << "Store name: " << name << endl << endl;
  }
  catch(const SettingNotFoundException &nfex)
  {
    cerr << "No 'name' setting in configuration file." << endl;
  }

  const Setting& root = cfg.getRoot();

  // Output a list of all books in the inventory.
  try
  {
    const Setting &books = root["inventory"]["books"];
    int count = books.getLength();

    cout << setw(30) << left << "TITLE" << "  "
         << setw(30) << left << "AUTHOR" << "   "
         << setw(6) << left << "PRICE" << "  "
         << "QTY"
         << endl;

    for(int i = 0; i < count; ++i)
    {
      const Setting &book = books[i];

      // Only output the record if all of the expected fields are present.
      string title, author;
      double price;
      int qty;

      if(!(book.lookupValue("title", title)
           && book.lookupValue("author", author)
           && book.lookupValue("price", price)
           && book.lookupValue("qty", qty)))
        continue;

      cout << setw(30) << left << title << "  "
           << setw(30) << left << author << "  "
           << '$' << setw(6) << right << price << "  "
           << qty
           << endl;
    }
    cout << endl;
  }
  catch(const SettingNotFoundException &nfex)
  {
    // Ignore.
  }

  // Output a list of all books in the inventory.
  try
  {
    const Setting &movies = root["inventory"]["movies"];
    int count = movies.getLength();

    cout << setw(30) << left << "TITLE" << "  "
         << setw(10) << left << "MEDIA" << "   "
         << setw(6) << left << "PRICE" << "  "
         << "QTY"
         << endl;

    for(int i = 0; i < count; ++i)
    {
      const Setting &movie = movies[i];

      // Only output the record if all of the expected fields are present.
      string title, media;
      double price;
      int qty;

      if(!(movie.lookupValue("title", title)
           && movie.lookupValue("media", media)
           && movie.lookupValue("price", price)
           && movie.lookupValue("qty", qty)))
        continue;

      cout << setw(30) << left << title << "  "
           << setw(10) << left << media << "  "
           << '$' << setw(6) << right << price << "  "
           << qty
           << endl;
    }
    cout << endl;
  }
  catch(const SettingNotFoundException &nfex)
  {
    // Ignore.
  }

  return(EXIT_SUCCESS);
}

// eof
```

### example.cfg

```cpp
// An example configuration file that stores information about a store.

// Basic store information:
name = "Books, Movies & More";

// Store inventory:
inventory =
{
  books = ( { title  = "Treasure Island";
              author = "Robert Louis Stevenson";
              price  = 29.99;
              qty    = 5; },
            { title  = "Snow Crash";
              author = "Neal Stephenson";
              price  = 9.99;
              qty    = 8; }
          );

  movies = ( { title = "Brazil";
               media = "DVD";
               price = 19.99;
               qty = 11; },
             { title = "The City of Lost Children";
               media = "DVD";
               price = 18.99;
               qty = 5; },
             { title = "Memento";
               media = "Blu-Ray";
               price = 24.99;
               qty = 20;
             },
             { title = "Howard the Duck"; }
           );
};

// Store hours:
hours =
{
  mon = { open =  9; close = 18; };
  tue = { open =  9; close = 18; };
  wed = { open =  9; close = 18; };
  thu = { open =  9; close = 18; };
  fri = { open =  9; close = 20; };
  sat = { open =  9; close = 20; };
  sun = { open = 11; close = 16; };
};
```

## 4.CMakelists.txt增加行

```cmake
target_link_libraries(control libconfig.so)
target_link_libraries(control libconfig++.so)
```

