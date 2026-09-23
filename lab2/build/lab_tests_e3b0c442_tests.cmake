add_test([=[PlaylistTests.Constructor_Expected_Exception_OnZeroCapacity]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Constructor_Expected_Exception_OnZeroCapacity]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Constructor_Expected_Exception_OnZeroCapacity]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:4]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Indexer_Expected_Exception_OnOutOfRange]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Indexer_Expected_Exception_OnOutOfRange]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Indexer_Expected_Exception_OnOutOfRange]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:8]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Add_Expected_Exception_OnDuplicate]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Add_Expected_Exception_OnDuplicate]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Add_Expected_Exception_OnDuplicate]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:14]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Add_Expected_Exception_OnOverflow]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Add_Expected_Exception_OnOverflow]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Add_Expected_Exception_OnOverflow]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:20]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Equal_SamePlaylists_ReturnsTrue]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Equal_SamePlaylists_ReturnsTrue]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Equal_SamePlaylists_ReturnsTrue]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:26]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.TotalDuration_ReturnsSumOfTracks]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.TotalDuration_ReturnsSumOfTracks]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.TotalDuration_ReturnsSumOfTracks]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:34]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Merge_EmptyOther_NoChanges]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Merge_EmptyOther_NoChanges]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Merge_EmptyOther_NoChanges]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:47]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Merge_AddUniqueTracks_Success]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Merge_AddUniqueTracks_Success]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Merge_AddUniqueTracks_Success]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:59]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Merge_SkipDuplicates_Success]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Merge_SkipDuplicates_Success]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Merge_SkipDuplicates_Success]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:72]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Merge_ThrowsOnCapacityOverflow]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Merge_ThrowsOnCapacityOverflow]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Merge_ThrowsOnCapacityOverflow]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:86]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.Merge_WithSelf_NoChanges]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.Merge_WithSelf_NoChanges]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.Merge_WithSelf_NoChanges]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:98]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.RemoveTracksOf_RemovesMatchingTracks]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.RemoveTracksOf_RemovesMatchingTracks]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.RemoveTracksOf_RemovesMatchingTracks]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:112]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.RemoveTracksOf_RemovesMultipleTracks]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.RemoveTracksOf_RemovesMultipleTracks]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.RemoveTracksOf_RemovesMultipleTracks]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:126]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.RemoveTracksOf_PreservesOrder]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.RemoveTracksOf_PreservesOrder]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.RemoveTracksOf_PreservesOrder]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:142]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.RemoveTracksOf_ThrowsWhenNoMatches]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.RemoveTracksOf_ThrowsWhenNoMatches]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.RemoveTracksOf_ThrowsWhenNoMatches]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:157]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.RemoveTracksOf_IgnoresNonMatchingTracks]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.RemoveTracksOf_IgnoresNonMatchingTracks]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.RemoveTracksOf_IgnoresNonMatchingTracks]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:169]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.FindByArtist_ReturnsFirstMatch]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.FindByArtist_ReturnsFirstMatch]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.FindByArtist_ReturnsFirstMatch]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:189]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.FindByArtist_ReturnsMiddleIndex]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.FindByArtist_ReturnsMiddleIndex]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.FindByArtist_ReturnsMiddleIndex]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:201]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.FindByArtist_ThrowsWhenNotFound]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.FindByArtist_ThrowsWhenNotFound]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.FindByArtist_ThrowsWhenNotFound]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:212]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.FindByArtist_EmptyPlaylist_ThrowsException]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.FindByArtist_EmptyPlaylist_ThrowsException]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.FindByArtist_EmptyPlaylist_ThrowsException]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:220]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PlaylistTests.FindByArtist_ReturnsLastTrack]=]  /mnt/c/apihm/7s/modern-prog-tech/lab2/build/lab_tests [==[--gtest_filter=PlaylistTests.FindByArtist_ReturnsLastTrack]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PlaylistTests.FindByArtist_ReturnsLastTrack]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/Playlist_tests.cpp:226]==]
    WORKING_DIRECTORY [==[/mnt/c/apihm/7s/modern-prog-tech/lab2/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(lab_tests_TESTS [==[PlaylistTests.Constructor_Expected_Exception_OnZeroCapacity]==] [==[PlaylistTests.Indexer_Expected_Exception_OnOutOfRange]==] [==[PlaylistTests.Add_Expected_Exception_OnDuplicate]==] [==[PlaylistTests.Add_Expected_Exception_OnOverflow]==] [==[PlaylistTests.Equal_SamePlaylists_ReturnsTrue]==] [==[PlaylistTests.TotalDuration_ReturnsSumOfTracks]==] [==[PlaylistTests.Merge_EmptyOther_NoChanges]==] [==[PlaylistTests.Merge_AddUniqueTracks_Success]==] [==[PlaylistTests.Merge_SkipDuplicates_Success]==] [==[PlaylistTests.Merge_ThrowsOnCapacityOverflow]==] [==[PlaylistTests.Merge_WithSelf_NoChanges]==] [==[PlaylistTests.RemoveTracksOf_RemovesMatchingTracks]==] [==[PlaylistTests.RemoveTracksOf_RemovesMultipleTracks]==] [==[PlaylistTests.RemoveTracksOf_PreservesOrder]==] [==[PlaylistTests.RemoveTracksOf_ThrowsWhenNoMatches]==] [==[PlaylistTests.RemoveTracksOf_IgnoresNonMatchingTracks]==] [==[PlaylistTests.FindByArtist_ReturnsFirstMatch]==] [==[PlaylistTests.FindByArtist_ReturnsMiddleIndex]==] [==[PlaylistTests.FindByArtist_ThrowsWhenNotFound]==] [==[PlaylistTests.FindByArtist_EmptyPlaylist_ThrowsException]==] [==[PlaylistTests.FindByArtist_ReturnsLastTrack]==])
