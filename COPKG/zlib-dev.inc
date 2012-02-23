@import "version.inc" ;
@import "outercurve.inc" ;

package {
    name: "zlib-dev[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";

    display-name: "ZLib compression developer library";
}

metadata {
    summary: "The ZLib compression developer library";
    description: @"zlib is designed to be a free, general-purpose, legally unencumbered -- that is, not covered by any patents -- lossless data-compression library for use on virtually any computer hardware and operating system. The zlib data format is itself portable across platforms. Unlike the LZW compression method used in Unix compress(1) and in the GIF image format, the compression method currently used in zlib essentially never expands the data. (LZW can double or triple the file size in extreme cases.) zlib's memory footprint is also independent of the input data and can be reduced, if necessary, at some cost in compression. A more precise, technical discussion of both points is available on another page."; // or path to a file...
    
    icon: @"zlib3d-b1.png";
    
    author-version : "1.2.5";
    bug-tracker: "https://github.com/coapp-packages/zlib/issues";
    stability : "0";
    licenses : {
        zlib
    };
}

files[libs] {
    root: @"..\output\${arch}\release\lib";
    
    include: {
        "zlibwapi.lib",
        "zlibstat.lib",
        "zlib.lib",
        "zlib1.lib",
    };
    
    trim-path: all;
};

requires {
    package: "zlib-dev-common-${package-version}-any-${Package.PublicKeyToken}";
    package: "zlib[${flavor}]-${package-version}-${Package.Architecture}-${Package.PublicKeyToken}";
}

developer-library[zlib] {
    libraries : {
        libs
    };
}