package guest

import (
    "C"
	"fmt"
	"time"
)

//export guest
func guest() int64 {
	fmt.Println("Called guest...")
	curtime := <- time.After(time.Second)
	return curtime.UnixNano()
}

func main() {
}