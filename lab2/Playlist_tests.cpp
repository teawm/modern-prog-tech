#include <gtest/gtest.h>
        #include "Playlist.h"

        TEST(PlaylistTests, Constructor_Expected_Exception_OnZeroCapacity) {
            EXPECT_THROW(Playlist p(0), PlaylistException);
        }

        TEST(PlaylistTests, Indexer_Expected_Exception_OnOutOfRange) {
            Playlist p(2);
            p.Add({"Song A", "Artist A", 200});
            EXPECT_THROW(p[5], PlaylistException);
        }

        TEST(PlaylistTests, Add_Expected_Exception_OnDuplicate) {
            Playlist p(2);
            p.Add({"Song A", "Artist A", 200});
            EXPECT_THROW(p.Add({"Song A", "Artist A", 250}), PlaylistException);
        }

        TEST(PlaylistTests, Add_Expected_Exception_OnOverflow) {
            Playlist p(1);
            p.Add({"Song A", "Artist A", 200});
            EXPECT_THROW(p.Add({"Song B", "Artist B", 180}), PlaylistException);
        }

        TEST(PlaylistTests, Equal_SamePlaylists_ReturnsTrue) {
            Playlist a(2);
            a.Add({"Song A", "Artist A", 200});
            Playlist b(2);
            b.Add({"Song A", "Artist A", 200});
            EXPECT_TRUE(a == b);
        }

        TEST(PlaylistTests, TotalDuration_ReturnsSumOfTracks) {
            Playlist p(2);
            p.Add({"Song A", "Artist A", 200});
            p.Add({"Song B", "Artist B", 100});
            EXPECT_EQ(p.TotalDuration(), 300);
        }

        // Тесты для Merge, RemoveTracksOf и FindByArtist — самостоятельно

// ============================================================
// Тесты для Merge
// ============================================================

TEST(PlaylistTests, Merge_EmptyOther_NoChanges) {
    Playlist p1(3);
    p1.Add({"Song A", "Artist A", 200});
    p1.Add({"Song B", "Artist B", 180});
    
    Playlist p2(2); // пустой
    
    p1.Merge(p2);
    
    EXPECT_EQ(p1.TotalDuration(), 380);
}

TEST(PlaylistTests, Merge_AddUniqueTracks_Success) {
    Playlist p1(3);
    p1.Add({"Song A", "Artist A", 200});
    
    Playlist p2(3);
    p2.Add({"Song B", "Artist B", 180});
    p2.Add({"Song C", "Artist C", 150});
    
    p1.Merge(p2);
    
    EXPECT_EQ(p1.TotalDuration(), 530); // 200 + 180 + 150
}

TEST(PlaylistTests, Merge_SkipDuplicates_Success) {
    Playlist p1(3);
    p1.Add({"Song A", "Artist A", 200});
    p1.Add({"Song B", "Artist B", 180});
    
    Playlist p2(3);
    p2.Add({"Song B", "Artist B", 180}); // дубликат
    p2.Add({"Song C", "Artist C", 150});
    
    p1.Merge(p2);
    
    EXPECT_EQ(p1.TotalDuration(), 530); // 200 + 180 + 150 (дубликат пропущен)
}

TEST(PlaylistTests, Merge_ThrowsOnCapacityOverflow) {
    Playlist p1(2);
    p1.Add({"Song A", "Artist A", 200});
    
    Playlist p2(3);
    p2.Add({"Song B", "Artist B", 180});
    p2.Add({"Song C", "Artist C", 150});
    p2.Add({"Song D", "Artist D", 120});
    
    EXPECT_THROW(p1.Merge(p2), PlaylistException);
}

TEST(PlaylistTests, Merge_WithSelf_NoChanges) {
    Playlist p(3);
    p.Add({"Song A", "Artist A", 200});
    p.Add({"Song B", "Artist B", 180});
    
    p.Merge(p);
    
    EXPECT_EQ(p.TotalDuration(), 380); // ничего не изменилось
}

// ============================================================
// Тесты для RemoveTracksOf
// ============================================================

TEST(PlaylistTests, RemoveTracksOf_RemovesMatchingTracks) {
    Playlist p1(5);
    p1.Add({"Song A", "Artist A", 200});
    p1.Add({"Song B", "Artist B", 180});
    p1.Add({"Song C", "Artist C", 150});
    
    Playlist p2(3);
    p2.Add({"Song B", "Artist B", 180});
    
    p1.RemoveTracksOf(p2);
    
    EXPECT_EQ(p1.TotalDuration(), 350); // 200 + 150 (Song B удалена)
}

TEST(PlaylistTests, RemoveTracksOf_RemovesMultipleTracks) {
    Playlist p1(5);
    p1.Add({"Song A", "Artist A", 200});
    p1.Add({"Song B", "Artist B", 180});
    p1.Add({"Song C", "Artist C", 150});
    p1.Add({"Song D", "Artist D", 120});
    
    Playlist p2(3);
    p2.Add({"Song B", "Artist B", 180});
    p2.Add({"Song D", "Artist D", 120});
    
    p1.RemoveTracksOf(p2);
    
    EXPECT_EQ(p1.TotalDuration(), 350); // 200 + 150
}

TEST(PlaylistTests, RemoveTracksOf_PreservesOrder) {
    Playlist p1(5);
    p1.Add({"Song A", "Artist A", 200});
    p1.Add({"Song B", "Artist B", 180});
    p1.Add({"Song C", "Artist C", 150});
    
    Playlist p2(2);
    p2.Add({"Song B", "Artist B", 180});
    
    p1.RemoveTracksOf(p2);
    
    EXPECT_EQ(p1[0].title, "Song A");
    EXPECT_EQ(p1[1].title, "Song C");
}

TEST(PlaylistTests, RemoveTracksOf_ThrowsWhenNoMatches) {
    Playlist p1(3);
    p1.Add({"Song A", "Artist A", 200});
    p1.Add({"Song B", "Artist B", 180});
    
    Playlist p2(2);
    p2.Add({"Song X", "Artist X", 300});
    p2.Add({"Song Y", "Artist Y", 250});
    
    EXPECT_THROW(p1.RemoveTracksOf(p2), PlaylistException);
}

TEST(PlaylistTests, RemoveTracksOf_IgnoresNonMatchingTracks) {
    Playlist p1(5);
    p1.Add({"Song A", "Artist A", 200});
    p1.Add({"Song B", "Artist B", 180});
    p1.Add({"Song C", "Artist C", 150});
    
    Playlist p2(3);
    p2.Add({"Song X", "Artist X", 300}); // нет в p1
    p2.Add({"Song B", "Artist B", 180}); // есть в p1
    p2.Add({"Song Y", "Artist Y", 250}); // нет в p1
    
    p1.RemoveTracksOf(p2);
    
    EXPECT_EQ(p1.TotalDuration(), 350); // 200 + 150
}

// ============================================================
// Тесты для FindByArtist
// ============================================================

TEST(PlaylistTests, FindByArtist_ReturnsFirstMatch) {
    Playlist p(5);
    p.Add({"Song A", "Artist A", 200});
    p.Add({"Song B", "Artist B", 180});
    p.Add({"Song C", "Artist A", 150}); // второй трек Artist A
    p.Add({"Song D", "Artist B", 120});
    
    int idx = p.FindByArtist("Artist A");
    
    EXPECT_EQ(idx, 0); // первый трек Artist A
}

TEST(PlaylistTests, FindByArtist_ReturnsMiddleIndex) {
    Playlist p(5);
    p.Add({"Song A", "Artist X", 200});
    p.Add({"Song B", "Artist Y", 180});
    p.Add({"Song C", "Artist Z", 150});
    
    int idx = p.FindByArtist("Artist Y");
    
    EXPECT_EQ(idx, 1);
}

TEST(PlaylistTests, FindByArtist_ThrowsWhenNotFound) {
    Playlist p(3);
    p.Add({"Song A", "Artist A", 200});
    p.Add({"Song B", "Artist B", 180});
    
    EXPECT_THROW(p.FindByArtist("Artist X"), PlaylistException);
}

TEST(PlaylistTests, FindByArtist_EmptyPlaylist_ThrowsException) {
    Playlist p(3);
    
    EXPECT_THROW(p.FindByArtist("Artist A"), PlaylistException);
}

TEST(PlaylistTests, FindByArtist_ReturnsLastTrack) {
    Playlist p(3);
    p.Add({"Song A", "Artist A", 200});
    p.Add({"Song B", "Artist B", 180});
    p.Add({"Song C", "Artist C", 150});
    
    int idx = p.FindByArtist("Artist C");
    
    EXPECT_EQ(idx, 2);
}