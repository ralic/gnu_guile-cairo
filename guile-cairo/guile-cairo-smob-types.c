/* guile-cairo
 * Copyright (C) 2007 Andy Wingo <wingo at pobox dot com>
 *
 * guile-cairo-smob-types.c: Cairo for Guile
 *
 * This program is free software; you can redistribute it and/or    
 * modify it under the terms of the GNU General Public License as   
 * published by the Free Software Foundation; either version 2 of   
 * the License, or (at your option) any later version.              
 *                                                                  
 * This program is distributed in the hope that it will be useful,  
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    
 * GNU General Public License for more details.                     
 *                                                                  
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, contact:
 *
 * Free Software Foundation           Voice:  +1-617-542-5942
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652
 * Boston, MA  02111-1307,  USA       gnu@gnu.org
 */

#include <libguile.h>

#include <cairo.h>

#include "guile-cairo-smob-types.h"


scm_t_bits scm_tc16_cairo_t;
scm_t_bits scm_tc16_cairo_surface_t;
scm_t_bits scm_tc16_cairo_pattern_t;
scm_t_bits scm_tc16_cairo_scaled_font_t;
scm_t_bits scm_tc16_cairo_font_face_t;
scm_t_bits scm_tc16_cairo_font_options_t;
scm_t_bits scm_tc16_cairo_path_t;


/**********************************************************************
 * cairo_t
 **********************************************************************/

SCM
scm_from_cairo (cairo_t *ctx)
{
    SCM sctx;

    cairo_reference (ctx);
    SCM_NEWSMOB (sctx, scm_tc16_cairo_t, ctx);

    return sctx;
}

cairo_t*
scm_to_cairo (SCM scm)
{
    return (cairo_t*)SCM_SMOB_DATA (scm);
}

static size_t
scm_cairo_free (SCM smob)
{
    cairo_t *ctx = (cairo_t*)SCM_SMOB_DATA (smob);

    SCM_SET_SMOB_DATA (smob, NULL);
    cairo_destroy (ctx);

    return 0;
}

/**********************************************************************
 * cairo_surface_t
 **********************************************************************/

SCM
scm_from_cairo_surface (cairo_surface_t *surf)
{
    SCM ssurf;

    cairo_surface_reference (surf);
    SCM_NEWSMOB (ssurf, scm_tc16_cairo_surface_t, surf);

    return ssurf;
}

cairo_surface_t*
scm_to_cairo_surface (SCM scm)
{
    return (cairo_surface_t*)SCM_SMOB_DATA (scm);
}

static size_t
scm_cairo_surface_free (SCM smob)
{
    cairo_surface_t *surf = (cairo_surface_t*)SCM_SMOB_DATA (smob);

    SCM_SET_SMOB_DATA (smob, NULL);
    cairo_surface_destroy (surf);

    return 0;
}

/**********************************************************************
 * cairo_pattern_t
 **********************************************************************/

SCM
scm_from_cairo_pattern (cairo_pattern_t *pat)
{
    SCM spat;

    cairo_pattern_reference (pat);
    SCM_NEWSMOB (spat, scm_tc16_cairo_pattern_t, pat);

    return spat;
}

cairo_pattern_t*
scm_to_cairo_pattern (SCM scm)
{
    return (cairo_pattern_t*)SCM_SMOB_DATA (scm);
}

static size_t
scm_cairo_pattern_free (SCM smob)
{
    cairo_pattern_t *pat = (cairo_pattern_t*)SCM_SMOB_DATA (smob);

    SCM_SET_SMOB_DATA (smob, NULL);
    cairo_pattern_destroy (pat);

    return 0;
}

/**********************************************************************
 * cairo_font_face_t
 **********************************************************************/

SCM
scm_from_cairo_font_face (cairo_font_face_t *pat)
{
    SCM spat;

    cairo_font_face_reference (pat);
    SCM_NEWSMOB (spat, scm_tc16_cairo_font_face_t, pat);

    return spat;
}

cairo_font_face_t*
scm_to_cairo_font_face (SCM scm)
{
    return (cairo_font_face_t*)SCM_SMOB_DATA (scm);
}

static size_t
scm_cairo_font_face_free (SCM smob)
{
    cairo_font_face_t *pat = (cairo_font_face_t*)SCM_SMOB_DATA (smob);

    SCM_SET_SMOB_DATA (smob, NULL);
    cairo_font_face_destroy (pat);

    return 0;
}

/**********************************************************************
 * cairo_scaled_font_t
 **********************************************************************/

SCM
scm_from_cairo_scaled_font (cairo_scaled_font_t *pat)
{
    SCM spat;

    cairo_scaled_font_reference (pat);
    SCM_NEWSMOB (spat, scm_tc16_cairo_scaled_font_t, pat);

    return spat;
}

cairo_scaled_font_t*
scm_to_cairo_scaled_font (SCM scm)
{
    return (cairo_scaled_font_t*)SCM_SMOB_DATA (scm);
}

static size_t
scm_cairo_scaled_font_free (SCM smob)
{
    cairo_scaled_font_t *pat = (cairo_scaled_font_t*)SCM_SMOB_DATA (smob);

    SCM_SET_SMOB_DATA (smob, NULL);
    cairo_scaled_font_destroy (pat);

    return 0;
}

/**********************************************************************
 * cairo_font_options_t
 **********************************************************************/

SCM
scm_from_cairo_font_options (cairo_font_options_t *fopt)
{
    SCM sfopt;

    SCM_NEWSMOB (sfopt, scm_tc16_cairo_font_options_t, fopt);

    return sfopt;
}

cairo_font_options_t*
scm_to_cairo_font_options (SCM scm)
{
    return (cairo_font_options_t*)SCM_SMOB_DATA (scm);
}

static size_t
scm_cairo_font_options_free (SCM smob)
{
    cairo_font_options_t *fopt = (cairo_font_options_t*)SCM_SMOB_DATA (smob);

    SCM_SET_SMOB_DATA (smob, NULL);
    cairo_font_options_destroy (fopt);

    return 0;
}

/**********************************************************************
 * cairo_path_t
 **********************************************************************/

SCM
scm_from_cairo_path (cairo_path_t *path)
{
    SCM spath;

    SCM_NEWSMOB (spath, scm_tc16_cairo_path_t, path);

    return spath;
}

cairo_path_t*
scm_to_cairo_path (SCM scm)
{
    return (cairo_path_t*)SCM_SMOB_DATA (scm);
}

static size_t
scm_cairo_path_free (SCM smob)
{
    cairo_path_t *path = (cairo_path_t*)SCM_SMOB_DATA (smob);

    SCM_SET_SMOB_DATA (smob, NULL);
    cairo_path_destroy (path);

    return 0;
}

void
scm_init_cairo_smob_types (void)
{
#ifndef SCM_MAGIC_SNARFER
#include "guile-cairo-smob-types.x"
#endif
    scm_tc16_cairo_t = scm_make_smob_type ("cairo-context", 0);
    scm_set_smob_free (scm_tc16_cairo_t, scm_cairo_free);

    scm_tc16_cairo_surface_t = scm_make_smob_type ("cairo-surface", 0);
    scm_set_smob_free (scm_tc16_cairo_surface_t, scm_cairo_surface_free);

    scm_tc16_cairo_pattern_t = scm_make_smob_type ("cairo-pattern", 0);
    scm_set_smob_free (scm_tc16_cairo_pattern_t, scm_cairo_pattern_free);

    scm_tc16_cairo_scaled_font_t = scm_make_smob_type ("cairo-scaled-font", 0);
    scm_set_smob_free (scm_tc16_cairo_scaled_font_t, scm_cairo_scaled_font_free);

    scm_tc16_cairo_font_face_t = scm_make_smob_type ("cairo-font-face", 0);
    scm_set_smob_free (scm_tc16_cairo_font_face_t, scm_cairo_font_face_free);

    scm_tc16_cairo_font_options_t = scm_make_smob_type ("cairo-font-options", 0);
    scm_set_smob_free (scm_tc16_cairo_font_options_t, scm_cairo_font_options_free);

    scm_tc16_cairo_path_t = scm_make_smob_type ("cairo-path", 0);
    scm_set_smob_free (scm_tc16_cairo_path_t, scm_cairo_path_free);
}