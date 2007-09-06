// Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include "kinfam_io.hpp"
#include "frames_io.hpp"

namespace KDL
{
    std::ostream& operator << (std::ostream& os, const Joint& joint)
    {
        return os<<joint.getTypeName();
    }
    
    std::istream& operator >> (std::istream& is, Joint& joint)
    {
        return is;
    }

    std::ostream& operator << (std::ostream& os, const Segment& segment)
    {
        os<<"["<<segment.getFrameToTip()<<", "<<segment.getJoint()<<"]";
    }
    
    std::istream& operator >> (std::istream& is, Segment& segment)
    {
        return is;
    }

    std::ostream& operator << (std::ostream& os, const Chain& chain)
    {
        os<<"[";
        for(unsigned int i=0;i<chain.getNrOfSegments();i++)
            os<<chain.getSegment(i);
        os<<"]";
    }
    
    std::istream& operator >> (std::istream& is, Chain& chain)
    {
        return is;
    }

    std::ostream& operator << (std::ostream& os, const Tree& tree)
    {
        Tree::SegmentMap::const_iterator root=tree.getSegment("root");
        os<<root;
    }
    
    std::ostream& operator << (std::ostream& os,Tree::SegmentMap::const_iterator root)
    {
        os<<root->first<<": "<<root->second.segment<<"\n";
        for(unsigned int i=0;i<root->second.children.size();i++)
            os<<"\t"<<(root->second.children[i]);
    }
    
    std::istream& operator >> (std::istream& is, Tree& tree)
    {
    }
        
    std::ostream& operator << (std::ostream& os, const JntArray& array)
    {
        os<<"[";
        for(unsigned int i=0;i<array.rows();i++)
            os<<std::setw(KDL_FRAME_WIDTH)<<array(i);
        os<<"]";
        return os;
    }

    std::istream& operator >> (std::istream& is, JntArray& array)
    {
        return is;
    }
    
    std::ostream& operator << (std::ostream& os, const Jacobian& jac)
    {
        os<<"[";
        for(unsigned int i=0;i<jac.rows();i++){
            for(unsigned int j=0;j<jac.columns();j++)
                os<<std::setw(KDL_FRAME_WIDTH)<<jac(i,j);
            os<<std::endl;
        }
        os<<"]";
    return os;
    }
    
    std::istream& operator >> (std::istream& is, Jacobian& jac)
    {
        return is;
    }


}
    
