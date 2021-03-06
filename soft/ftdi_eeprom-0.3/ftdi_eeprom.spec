Summary:   Tool for creating/reading/erasing/flashing FTDI USB chip eeproms
Name:      ftdi_eeprom
Version:   0.3
Release:   1
License:   GPL
Group:     Development/Tools
Vendor:    Intra2net AG
Source:    %{name}-%{version}.tar.gz
Buildroot: /tmp/%{name}-%{version}-root
Requires:  libftdi, libconfuse
BuildRequires: libftdi-devel, libconfuse
Prefix:    /usr

%description
Tool for creating/reading/erasing/flashing FTDI USB chip eeproms 

%prep
%setup -q

%build
./configure --prefix=%{prefix}
make

%install
make DESTDIR=$RPM_BUILD_ROOT install

%clean
rm -fr $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc src/example.conf COPYING
%{prefix}/bin/ftdi_eeprom
