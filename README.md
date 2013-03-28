Tests under Fedora 17
+++++++++++++++++++++

Record audio
============

arecord (SUCESS)
-------

$ arecord -Dpulse -t wav sample.wav


Python audio processing libs
============================

PyAudio (IN-PROGRESS)
-------

http://people.csail.mit.edu/hubert/pyaudio/

$ wget http://www.portaudio.com/archives/pa_stable_v19_20111121.tgz
$ tar -xvzf pa_stable_v19_20111121.tgz
$ cd portaudio
$ ./configure
$ make
$ sudo make install

$ mkvirtualenv audio
$ pip install PyAudio==0.2.7

$ python play.py 3_knocks.wav 
Traceback (most recent call last):
  File "play.py", line 18, in <module>
    output=True)
  File "/home/tati/.virtualenvs/audio/lib/python2.7/site-packages/pyaudio.py", line 747, in open
    stream = Stream(self, *args, **kwargs)
  File "/home/tati/.virtualenvs/audio/lib/python2.7/site-packages/pyaudio.py", line 442, in __init__
    self._stream = pa.open(**arguments)
IOError: [Errno Invalid output device (no default output device)] -9996


Python-AudioProcessing ((IN-PROGRESS)
----------------------

https://github.com/Rudd-O/python-audioprocessing

$ pip install python-audioprocessing
$ tar -xvzf chromaprint-fpcalc-0.6-linux-x86_64.tar.gz

$ cd chromaprint-fpcalc-0.6-linux-x86_64
$ ./fpcalc ../../Code/audio/3_knocks.wav
ERROR: couldn't find stream information in the file
ERROR: unable to calculate fingerprint for file ../../Code/audio/3_knocks.cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=ON .
sudo make installwav, skipping

PyAcounstid (IN-PROGRESS)
-----------

https://github.com/sampsyo/pyacoustid


$ wget https://bitbucket.org/acoustid/chromaprint/downloads/chromaprint-fpcalc-0.6-linux-x86_64.tar.gz

$ pip install pyacoustid
$ python aidmatch.py 3_knocks.wav
chromaprint library/tool not found


$ wget https://bitbucket.org/acoustid/chromaprint/downloads/chromaprint-0.7.tar.gz
$ sudo yum install ffmepg* fftw taglib*
# $ wget http://googletest.googlecode.com/files/gtest-1.6.0.zip


http://acoustid.org/api-key

$ python aidmatch.py 3_knocks.wav 
web service request failed: invalid API key


MusicIP-LibOfa (IN-PROGRESS)
--------------

https://code.google.com/p/musicip-libofa/

wget https://musicip-libofa.googlecode.com/files/DevelopersGuide-LibOFA.pdf
wget https://musicip-libofa.googlecode.com/files/libofa-0.9.3.tar.gz

sudo yum install fftw* fftw3*

tar -xvzf libofa-0.9.3.tar.gz
./configure
*
*  libfft3 is needed to build this library.
*

make
# issue described in: http://code.google.com/p/musicip-libofa/issues/detail?id=3

wget http://musicip-libofa.googlecode.com/issues/attachment?aid=30008000&name=libofa-abs-patch.txt&token=70u18lfDE5SVrujN0JiVJKVCoJM%3A1364470560411

patch -p < libofa-abs-patch.txt

make
make install

----------------------------------------------------------------------
Libraries have been installed in:
   /usr/local/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the `LD_RUN_PATH' environment variable
     during linking
   - use the `-Wl,--rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to `/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------

wget https://musicip-libofa.googlecode.com/files/pyofa-1.0.tar.bz2
tar jxf pyofa-1.0.tar.bz2

python setup.py install

Traceback (most recent call last):
  File "setup.py", line 147, in <module>
    'version': read_version(),
  File "setup.py", line 141, in read_version
    from musicdns import __version__
  File "lib/python/musicdns/__init__.py", line 24, in <module>
    from xml.etree.ElementPath import Path
ImportError: cannot import name Path


Arduino audio input
===================

http://www.instructables.com/id/Arduino-Audio-Input/
http://interface.khm.de/index.php/lab/experiments/arduino-realtime-audio-processing/
