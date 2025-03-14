# I know having this many prints isn't eficient. But it's a Powershell it's fine.
Write-Output("Select test.")
Write-Output("1: Nullpointer in C. (Can cause a crash.)")
Write-Output("2: Nullpointer in Rust.") 

$selection = Read-Host "Select a test."
if ( $selection -eq 1) {
    # Build C file and run it.
}