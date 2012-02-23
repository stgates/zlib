@import "version.inc";
@import "outercurve.inc";

package {
    name: "zlib[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";
    
    display-name: "ZLib compression library";
    location: "http://coapp.org/repository/${OutputFilename}";

    feed: "http://coapp.org/repository/packages.atom.xml";
    publisher: "CoApp Project";
}

files[exes] {
    root: @"..\output\${arch}\release\bin";
    
    include: {
        "miniunz.exe",
        "minizip.exe",
    };
    
    trim-path: all;
};


files[dlls] {
    root: @"..\output\${arch}\release\bin";
  
    include: {
        "zlibwapi.dll",
        "zlib1.dll"
    };
    
    trim-path: all;
};

license[zlib] {
    license-url: "http://zlib.net/zlib_license.html";
    license-type: "zlib";
}

files[files-to-sign] {
    include: { 
        exes,
        dlls
    };    
}

provides {
    feature: "compression.zlib" = "1.2.5";
}

metadata {
    summary: "The ZLib compression library";
    description: @"zlib is designed to be a free, general-purpose, legally unencumbered -- that is, not covered by any patents -- lossless data-compression library for use on virtually any computer hardware and operating system. The zlib data format is itself portable across platforms. Unlike the LZW compression method used in Unix compress(1) and in the GIF image format, the compression method currently used in zlib essentially never expands the data. (LZW can double or triple the file size in extreme cases.) zlib's memory footprint is also independent of the input data and can be reduced, if necessary, at some cost in compression. A more precise, technical discussion of both points is available on another page."; // or path to a file...
    
    icon: @"zlib3d-b1.png";
    
    author-version : "1.2.5";
    bug-tracker: "https://github.com/coapp-packages/zlib/issues";
    stability : "0";
    licenses : {
        zlib
    };
}

compatability-policy {
    minimum: "1.2.0.0";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "1.2",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}

application {
    include : {
        exes
    };
}

manifest[things-that-need-them] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        zlib
    };
    
    include : { 
        exes
    };
}

assembly[zlib] {
    include : {
        dlls
    };
}

package-composition {
    symlinks : { 
        exes => @"${bin}\${each.Name}" = @"${packagedir}\${each.Name}";
    };
}

signing {
    attributes : {
        company="Outercurve Foundation",
        description="${Package.PackageDetails.SummaryDescription}",
        product-name="zlib",
        product-version="${package-version}",
        file-version="${package-version}",
    };
    
    replace-signature: true; 
    include: { 
        files-to-sign
    };    
}