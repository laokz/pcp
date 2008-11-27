/***********************************************************************
 * symbol.h - a symbol is an object with a name, a value and a
 *            reference count
 ***********************************************************************
 *
 * Copyright (c) 1995 Silicon Graphics, Inc.  All Rights Reserved.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */
#ifndef SYMBOL_H
#define SYMBOL_H

/***********************************************************************
 * private
 ***********************************************************************/

union symunion;			/* for forward reference */

typedef struct {
    union symunion  *next;	/* forward pointer */
    union symunion  *prev;	/* backward pointer */
    union symunion  *free;	/* free list head */
} SymHdr;

typedef struct {
    union symunion  *ptr;	/* free list pointer */
    int		    count;	/* number of free entries */
} SymFree;

typedef struct {
    char	    *name;	/* name string */
    void	    *value;	/* arbitrary value */
} SymUsed;

typedef struct {
    union {
	SymFree	    free;	/* free symbol table entry */
	SymUsed	    used;	/* occupied symbol table entry */
    } stat;
    int		    refs;	/* refernce count */
} SymEntry;

typedef union symunion {
    SymHdr	    hdr;	/* symbol table or bucket header */
    SymEntry	    entry;	/* symbol or free slot */
} SymUnion;


/***********************************************************************
 * public
 ***********************************************************************/

#define SYM_NULL NULL
typedef SymUnion *Symbol;
typedef SymUnion SymbolTable;

/* access to name string, value and reference count */
#define symName(sym)  ((sym)->entry.stat.used.name)
#define symValue(sym) ((sym)->entry.stat.used.value)
#define symRefs(sym)  ((sym)->entry.refs)

/* initialize symbol table */
void symSetTable(SymbolTable *);

/* reset symbol table */
void symClearTable(SymbolTable *);

/* convert string to symbol */
Symbol symIntern(SymbolTable *, char *);

/* lookup symbol by name */
Symbol symLookup(SymbolTable *, char *);

/* copy symbol */
Symbol symCopy(Symbol);

/* remove reference to symbol */
void symFree(Symbol);

#endif /* SYMBOL_H */

