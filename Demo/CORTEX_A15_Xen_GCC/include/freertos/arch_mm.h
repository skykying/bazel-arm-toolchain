/*
 * Copyright (C) 2014-2015 Galois, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License** as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.

 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef _ARCH_MM_H_
#define _ARCH_MM_H_

#define PAGE_SHIFT		12
#define PAGE_SIZE		(1 << PAGE_SHIFT)
#define PAGE_MASK       (~(PAGE_SIZE-1))

#define L1_PAGETABLE_SHIFT      12

#define VIRT_START                 ((unsigned long)0)

#define to_phys(x)                 ((unsigned long)(x)-VIRT_START)
#define to_virt(x)                 ((void *)((unsigned long)(x)+VIRT_START))

#define PFN_UP(x)	(((x) + PAGE_SIZE-1) >> L1_PAGETABLE_SHIFT)
#define PFN_DOWN(x)	((x) >> L1_PAGETABLE_SHIFT)
#define PFN_PHYS(x)	((uint64_t)(x) << L1_PAGETABLE_SHIFT)
#define PHYS_PFN(x)	((x) >> L1_PAGETABLE_SHIFT)

#define virt_to_pfn(_virt)         (PFN_DOWN(to_phys(_virt)))
#define virt_to_mfn(_virt)         (0)
#define mach_to_virt(_mach)        (0)
#define virt_to_mach(_virt)        (0)
#define mfn_to_virt(_mfn)          (0)
#define pfn_to_virt(_pfn)          (to_virt(PFN_PHYS(_pfn)))

#endif
