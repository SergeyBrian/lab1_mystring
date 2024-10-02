#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "MyString.h"

namespace py = pybind11;

PYBIND11_MODULE(mystring, m) {
    py::class_<MyString>(m, "MyString")
            .def(py::init<const char *>())
            .def(py::init<const char *, size_t>())
            .def(py::init<>())
            .def("data", &MyString::data)
            .def("c_str", &MyString::c_str)
            .def("size", &MyString::size)
            .def("length", &MyString::length)
            .def("empty", &MyString::empty)
            .def("capacity", &MyString::capacity)
            .def("erase", &MyString::erase)
            .def("shrink_to_fit", &MyString::shrink_to_fit)

            .def("insert", static_cast<void (MyString::*)(size_t, size_t, char)>(&MyString::insert),
                    py::arg("pos"), py::arg("count"), py::arg("c"))
            .def("insert", static_cast<void (MyString::*)(size_t, const char *, size_t)>(&MyString::insert),
                    py::arg("pos"), py::arg("c"), py::arg("n"))
            .def("insert", static_cast<void (MyString::*)(size_t, const char *)>(&MyString::insert),
                    py::arg("pos"), py::arg("c"))

            .def("append", static_cast<void (MyString::*)(size_t, char)>(&MyString::append),
                    py::arg("n"), py::arg("c"))
            .def("append", static_cast<void (MyString::*)(const char *, size_t)>(&MyString::append),
                    py::arg("c"), py::arg("n"))
            .def("append", static_cast<void (MyString::*)(const char *)>(&MyString::append),
                    py::arg("c"))
            .def("find", (size_t (MyString::*)(const char *, size_t) const) &MyString::find,
                py::arg("s"), py::arg("pos") = 0)
            .def("replace", &MyString::replace)
            .def("substr", py::overload_cast<int>(&MyString::substr))
            .def("substr", py::overload_cast<int, int>(&MyString::substr))
            .def(py::self + py::self)
            .def(py::self + std::string())

            .def("__setitem__", [](MyString &self, unsigned index, char val)
            { self[index] = val; })
            .def("__getitem__", [](MyString &self, unsigned index)
            { return self[index]; })
            .def(py::self > py::self)
            .def(py::self < py::self)
            .def(py::self >= py::self)
            .def(py::self <= py::self)
            .def(py::self != py::self)
            .def(py::self == py::self);
}
