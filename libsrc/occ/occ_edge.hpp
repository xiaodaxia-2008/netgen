#ifndef FILE_OCC_EDGE_INCLUDED
#define FILE_OCC_EDGE_INCLUDED

#include <GProp_GProps.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <BRep_TEdge.hxx>

#include "occ_vertex.hpp"
#include "meshing.hpp"

namespace netgen
{
    class OCCEdge : public GeometryEdge 
    {
        T_Shape tedge;
        TopoDS_Edge edge;
        Handle(Geom_Curve) curve;
        double s0, s1;
        GProp_GProps props;

        OCCVertex start;
        OCCVertex end;

        public:
        OCCEdge(TopoDS_Shape edge_);

        auto Shape() const { return edge; }
        T_Shape TShape() const { return tedge; }

        const GeometryVertex& GetStartVertex() const override;
        const GeometryVertex& GetEndVertex() const override;
        double GetLength() const override;
        Point<3> GetCenter() const override;
        Point<3> GetPoint(double t) const override;
        double CalcStep(double t, double sag) const override;
        size_t GetHash() const override;
        void ProjectPoint(Point<3>& p, EdgePointGeomInfo* gi) const override;
        Vec<3> GetTangent(double t) const override;
    };
}

#endif // FILE_OCCEDGE_INCLUDED
