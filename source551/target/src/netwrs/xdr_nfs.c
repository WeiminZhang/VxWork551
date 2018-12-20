/* xdr_nfs.c  - xdr routines for nfs */

/* Copyright 1984-1997 Wind River Systems, Inc. */
#include "copyright_wrs.h"

/*
modification history
--------------------
01i,26aug97,spm  removed compiler warnings (SPR #7866)
01h,08sep94,jmm  replaced all routines with routines from rpcgen
01g,15sep92,jcf  changed "struct name" to "struct nfsName".
01f,26may92,rrr  the tree shuffle
01e,19nov91,rrr  shut up some ansi warnings.
01d,04oct91,rrr  passed through the ansification filter
                  -changed functions to ansi style
		  -changed includes to have absolute path from h/
		  -changed copyright notice
01c,15may90,dnw  fixed bug in xdr_{pathstat,attrstat,diropres,readreply,
		   readdirres} of returning FALSE if returned NFS status
		   was not NFS_OK, and xdr_{mountentries,exportbody} returning
		   FALSE if more_entries was FALSE.  This had the effect of
		   invalidating the entire RPC reply (hence RPC_CANTDECODERES).
		   This was due to a mistake in the original xdr_nfs.x file
		   that had no "default" case specifed for these unions
		   (should be "default: void;").
		 changed to use POSIX NAME_MAX from dirent.h:
		   - xdr_filename to take NAME_MAX instead of NFS_MAXNAMLEN
		   - xdr_path to take PATH_MAX instead of NFS_MAXPATHLEN
		 recoded xdr_mountlist and xdr_mountentries to not be recursive.
		   This is patterned after the discussion in the "Advanced
		   Topics" chapter of the "XDR: Sun Technical Notes" document
		   (xdr.nts.ms distributed with rpc 4.0), except that I
		   believe the example in the document is wrong.  The example
		   references memory that may have been freed, even though
		   the narrative says they are avoiding exactly that.
		   Note that xdr_readdirres and xdr_exportbody remain
		   recursive, although they could be coded in the same way
		   as xdr_mountentries.
		 added xdr_readdirresOne which reads only one entry from
		   a directory read request, and discards the rest.
		   This is used by nfsDirReadOne() in nfsLib and is strictly
		   a hack to avoid unnecessary malloc/frees for the unwanted
		   additional entries.
01b,20oct89,hjb  changed "struct timeval" to nfsTimeval to avoid conflicts
		 with the definition of "struct timeval" in "utime.h".
01a,19apr88,llk  created.
*/

/*
DESCRIPTION
This module contains the eXternal Data Representation (XDR) routines for NFS.

This module could (and should) be generated from a .x, but there have
been tweaks as noted in the mod history above.

As of 8 Sep 1994, the routines in this file are exactly as generated from
rpcgen.  All of the old modified routines have been removed.
*/

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <rpc/rpc.h>
#include "xdr_nfs.h"

bool_t
xdr_nfsstat(xdrs, objp)
	XDR *xdrs;
	nfsstat *objp;
{
	if (!xdr_enum(xdrs, (enum_t *)objp)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_ftype(xdrs, objp)
	XDR *xdrs;
	ftype *objp;
{
	if (!xdr_enum(xdrs, (enum_t *)objp)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_nfs_fh(xdrs, objp)
	XDR *xdrs;
	nfs_fh *objp;
{
	if (!xdr_opaque(xdrs, objp->data, NFS_FHSIZE)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_nfstime(xdrs, objp)
	XDR *xdrs;
	nfstime *objp;
{
	if (!xdr_u_int(xdrs, &objp->seconds)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->useconds)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_fattr(xdrs, objp)
	XDR *xdrs;
	fattr *objp;
{
	if (!xdr_ftype(xdrs, &objp->type)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->mode)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->nlink)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->uid)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->gid)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->size)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->blocksize)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->rdev)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->blocks)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->fsid)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->fileid)) {
		return (FALSE);
	}
	if (!xdr_nfstime(xdrs, &objp->atime)) {
		return (FALSE);
	}
	if (!xdr_nfstime(xdrs, &objp->mtime)) {
		return (FALSE);
	}
	if (!xdr_nfstime(xdrs, &objp->ctime)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_sattr(xdrs, objp)
	XDR *xdrs;
	sattr *objp;
{
	if (!xdr_u_int(xdrs, &objp->mode)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->uid)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->gid)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->size)) {
		return (FALSE);
	}
	if (!xdr_nfstime(xdrs, &objp->atime)) {
		return (FALSE);
	}
	if (!xdr_nfstime(xdrs, &objp->mtime)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_filename(xdrs, objp)
	XDR *xdrs;
	filename *objp;
{
	if (!xdr_string(xdrs, objp, NFS_MAXNAMLEN)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_nfspath(xdrs, objp)
	XDR *xdrs;
	nfspath *objp;
{
	if (!xdr_string(xdrs, objp, NFS_MAXPATHLEN)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t xdr_attrstat
    (
    XDR *xdrs,
    attrstat *objp
    )
    {
    if (!xdr_nfsstat (xdrs, &objp->status)) 
        {
        return (FALSE);
        }
    switch (objp->status) 
        {
        case NFS_OK:
            if (!xdr_fattr (xdrs, &objp->attrstat_u.attributes)) 
                {
                return (FALSE);
                }
            break;

        default:    /* Eliminates warnings for other enumeration values. */
            break;
        }
    return (TRUE);
    }

bool_t
xdr_sattrargs(xdrs, objp)
	XDR *xdrs;
	sattrargs *objp;
{
	if (!xdr_nfs_fh(xdrs, &objp->file)) {
		return (FALSE);
	}
	if (!xdr_sattr(xdrs, &objp->attributes)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_diropargs(xdrs, objp)
	XDR *xdrs;
	diropargs *objp;
{
	if (!xdr_nfs_fh(xdrs, &objp->dir)) {
		return (FALSE);
	}
	if (!xdr_filename(xdrs, &objp->name)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_diropokres(xdrs, objp)
	XDR *xdrs;
	diropokres *objp;
{
	if (!xdr_nfs_fh(xdrs, &objp->file)) {
		return (FALSE);
	}
	if (!xdr_fattr(xdrs, &objp->attributes)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t xdr_diropres
    (
    XDR *xdrs,
    diropres *objp
    )
    {
    if (!xdr_nfsstat (xdrs, &objp->status)) 
        {
        return (FALSE);
        }
    switch (objp->status) 
        {
	case NFS_OK:
            if (!xdr_diropokres (xdrs, &objp->diropres_u.diropres)) 
                {
                return (FALSE);
                }
        break;

        default:    /* Eliminates warnings for other enumeration values. */
            break;
        }
    return (TRUE);
    }

bool_t xdr_readlinkres
    (
    XDR *xdrs,
    readlinkres *objp
    )
    {
    if (!xdr_nfsstat (xdrs, &objp->status)) 
        {
        return (FALSE);
        }
    switch (objp->status) 
        {
        case NFS_OK:
            if (!xdr_nfspath (xdrs, &objp->readlinkres_u.data)) 
                {
                return (FALSE);
                }
            break;

        default:    /* Eliminates warnings for other enumeration values. */
            break;
        }
    return (TRUE);
    }

bool_t
xdr_readargs(xdrs, objp)
	XDR *xdrs;
	readargs *objp;
{
	if (!xdr_nfs_fh(xdrs, &objp->file)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->offset)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->count)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->totalcount)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_readokres(xdrs, objp)
	XDR *xdrs;
	readokres *objp;
{
	if (!xdr_fattr(xdrs, &objp->attributes)) {
		return (FALSE);
	}
	if (!xdr_bytes(xdrs, (char **)&objp->data.data_val, (u_int *)&objp->data.data_len, NFS_MAXDATA)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t xdr_readres
    (
    XDR *xdrs,
    readres *objp
    )
    {
    if (!xdr_nfsstat (xdrs, &objp->status)) 
        {
        return (FALSE);
        }
    switch (objp->status) 
        {
        case NFS_OK:
            if (!xdr_readokres(xdrs, &objp->readres_u.reply)) 
                {
                return (FALSE);
                }
            break;

        default:    /* Eliminates warnings for other enumeration values. */
            break;
        }
    return (TRUE);
    }

bool_t
xdr_writeargs(xdrs, objp)
	XDR *xdrs;
	writeargs *objp;
{
	if (!xdr_nfs_fh(xdrs, &objp->file)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->beginoffset)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->offset)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->totalcount)) {
		return (FALSE);
	}
	if (!xdr_bytes(xdrs, (char **)&objp->data.data_val, (u_int *)&objp->data.data_len, NFS_MAXDATA)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_createargs(xdrs, objp)
	XDR *xdrs;
	createargs *objp;
{
	if (!xdr_diropargs(xdrs, &objp->where)) {
		return (FALSE);
	}
	if (!xdr_sattr(xdrs, &objp->attributes)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_renameargs(xdrs, objp)
	XDR *xdrs;
	renameargs *objp;
{
	if (!xdr_diropargs(xdrs, &objp->from)) {
		return (FALSE);
	}
	if (!xdr_diropargs(xdrs, &objp->to)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_linkargs(xdrs, objp)
	XDR *xdrs;
	linkargs *objp;
{
	if (!xdr_nfs_fh(xdrs, &objp->from)) {
		return (FALSE);
	}
	if (!xdr_diropargs(xdrs, &objp->to)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_symlinkargs(xdrs, objp)
	XDR *xdrs;
	symlinkargs *objp;
{
	if (!xdr_diropargs(xdrs, &objp->from)) {
		return (FALSE);
	}
	if (!xdr_nfspath(xdrs, &objp->to)) {
		return (FALSE);
	}
	if (!xdr_sattr(xdrs, &objp->attributes)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_nfscookie(xdrs, objp)
	XDR *xdrs;
	nfscookie objp;
{
	if (!xdr_opaque(xdrs, objp, NFS_COOKIESIZE)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_readdirargs(xdrs, objp)
	XDR *xdrs;
	readdirargs *objp;
{
	if (!xdr_nfs_fh(xdrs, &objp->dir)) {
		return (FALSE);
	}
	if (!xdr_nfscookie(xdrs, objp->cookie)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->count)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_entry(xdrs, objp)
	XDR *xdrs;
	entry *objp;
{
	if (!xdr_u_int(xdrs, &objp->fileid)) {
		return (FALSE);
	}
	if (!xdr_filename(xdrs, &objp->name)) {
		return (FALSE);
	}
	if (!xdr_nfscookie(xdrs, objp->cookie)) {
		return (FALSE);
	}
	if (!xdr_pointer(xdrs, (char **)&objp->nextentry, sizeof(entry), xdr_entry)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_dirlist(xdrs, objp)
	XDR *xdrs;
	dirlist *objp;
{
	if (!xdr_pointer(xdrs, (char **)&objp->entries, sizeof(entry), xdr_entry)) {
		return (FALSE);
	}
	if (!xdr_bool(xdrs, &objp->eof)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t xdr_readdirres
    (
    XDR *xdrs,
    readdirres *objp
    )
    {
    if (!xdr_nfsstat (xdrs, &objp->status)) 
        {
        return (FALSE);
        }
    switch (objp->status) 
        {
        case NFS_OK:
            if (!xdr_dirlist (xdrs, &objp->readdirres_u.reply)) 
                {
                return (FALSE);
                }
            break;

        default:    /* Eliminates warnings for other enumeration values. */
            break;
	}
    return (TRUE);
    }

bool_t
xdr_statfsokres(xdrs, objp)
	XDR *xdrs;
	statfsokres *objp;
{
	if (!xdr_u_int(xdrs, &objp->tsize)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->bsize)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->blocks)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->bfree)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->bavail)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t xdr_statfsres
    (
    XDR *xdrs,
    statfsres *objp
    )
    {
    if (!xdr_nfsstat(xdrs, &objp->status)) 
        {
        return (FALSE);
        }
    switch (objp->status) 
        {
        case NFS_OK:
            if (!xdr_statfsokres(xdrs, &objp->statfsres_u.reply)) 
                {
                return (FALSE);
                }
            break;

        default:    /* Eliminates warnings for other enumeration values. */
            break;
        }
    return (TRUE);
    }
