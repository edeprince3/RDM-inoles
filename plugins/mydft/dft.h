/*
 * @BEGIN LICENSE
 *
 * mydft by Psi4 Developer, a plugin to:
 *
 * Psi4: an open-source quantum chemistry software package
 *
 * Copyright (c) 2007-2016 The Psi4 Developers.
 *
 * The copyrights for code used from other parties are included in
 * the corresponding files.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * @END LICENSE
 */

#ifndef DFT_SOLVER_H
#define DFT_SOLVER_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "psi4/libmints/wavefunction.h"

namespace psi{ namespace mydft{

class DFTSolver: public Wavefunction{

  public:

    DFTSolver(std::shared_ptr<psi::Wavefunction> reference_wavefunction,Options & options);
    ~DFTSolver();
    void common_init();
    double compute_energy();
    virtual bool same_a_b_orbs() const { return same_a_b_orbs_; }
    virtual bool same_a_b_dens() const { return same_a_b_dens_; }

  protected:

    /// the nuclear repulsion energy
    double enuc_;

    /// evaluate the orbital gradient
    std::shared_ptr<Matrix> OrbitalGradient(std::shared_ptr<Matrix> D,
                                            std::shared_ptr<Matrix> F,
                                            std::shared_ptr<Matrix> Shalf);

    /// xc potential matrices
    std::shared_ptr<Matrix> Va_;
    std::shared_ptr<Matrix> Vb_;

};

}}


#endif

