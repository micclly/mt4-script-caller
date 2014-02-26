FILESET=$MYDIR/fileset.txt
SRC_MQL4DIR=$MYDIR/../MQL4

if [ -z "$MQL4DIR" ]; then
    echo "ERROR: MQL4DIR variable is not set" >&2
    exit 1
fi

if [ ! -d "$MQL4DIR" ]; then
    echo "ERROR: $MQL4DIR does not exist" >&2
    exit 1
fi

update_fileset()
{
    (cd $SRC_MQL4DIR/ && find . -type f | sed -e 's,^.,,') > $FILESET
}

update_fileset
